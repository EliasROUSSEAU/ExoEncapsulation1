#include "World.h"
#include <iostream>
#include <cmath>

float CalculateDistance(Vector2 _pos1, Vector2 _pos2) {
    float dx = _pos1.GetX() - _pos2.GetX();
    float dy = _pos1.GetY() - _pos2.GetY();
    return std::sqrt(dx * dx + dy * dy);
}

World::World() {
    entities = new Entity * [100];
    entityCount = 0;
}

World::~World() {
    for (int i = 0; i < entityCount; ++i) {
        delete entities[i];
    }
    delete[] entities;
}

void World::Init() {
    entities[entityCount++] = new StaticObject(0, 0);
    entities[entityCount++] = new BreakableObject(5, 5, 1, 1);
    entities[entityCount++] = new Mob(3, 3, 20, 20, Vector2(1, 0), 1.0f);
    entities[entityCount++] = new Player(1, 1, 10, 10, Vector2(0.5f, 0.5f), 1.0f);
}

// Simulation
void World::Step() {
    bool allDead = true;

    for (int i = 0; i < entityCount; ++i) {
        if (entities[i] != nullptr) {
            // Gestion des Mobs
            if (Mob* mob = dynamic_cast<Mob*>(entities[i])) {
                allDead = false; // Au moins un Mob est vivant
                // Cherche un BreakableObject
                for (int j = 0; j < entityCount; ++j) {
                    if (BreakableObject* breakable = dynamic_cast<BreakableObject*>(entities[j])) {
                        // Vérifie la distance et déplace le Mob vers le BreakableObject
                        if (CalculateDistance(mob->GetPosition(), breakable->GetPosition()) > 1.0f) {
                            Vector2 mobPos = mob->GetPosition();
                            Vector2 breakablePos = breakable->GetPosition();

                            // Déplacement vers le BreakableObject
                            if (mobPos.GetX() < breakablePos.GetX()) {
                                mob->SetPosition(mobPos.GetX() + 1, mobPos.GetY());
                            }
                            else if (mobPos.GetX() > breakablePos.GetX()) {
                                mob->SetPosition(mobPos.GetX() - 1, mobPos.GetY());
                            }
                            if (mobPos.GetY() < breakablePos.GetY()) {
                                mob->SetPosition(mobPos.GetX(), mobPos.GetY() + 1);
                            }
                            else if (mobPos.GetY() > breakablePos.GetY()) {
                                mob->SetPosition(mobPos.GetX(), mobPos.GetY() - 1);
                            }
                        }
                    }
                }
            }
            // Gestion des Players
            else if (Player* player = dynamic_cast<Player*>(entities[i])) {
                allDead = false; // Au moins un Player est vivant
                bool mobAlive = false;

                // Cherche un Mob vivant
                for (int j = 0; j < entityCount; ++j) {
                    if (Mob* mob = dynamic_cast<Mob*>(entities[j])) {
                        if (mob->GetLife() > 0) {
                            mobAlive = true;

                            // Si le Mob est à portée, attaque
                            if (CalculateDistance(player->GetPosition(), mob->GetPosition()) < 1.0f) {
                                player->Attack(mob); // Attaque le Mob
                            }
                            break;
                        }
                    }
                }

                // Si aucun Mob n'est vivant, attaque un BreakableObject
                if (!mobAlive) {
                    for (int j = 0; j < entityCount; ++j) {
                        if (BreakableObject* breakable = dynamic_cast<BreakableObject*>(entities[j])) {
                            if (CalculateDistance(player->GetPosition(), breakable->GetPosition()) < 1.0f) {
                                player->Attack(breakable); // Attaque le BreakableObject
                                break;
                            }
                        }
                    }
                }
            }
        }
    }

    // Si tous les Mobs et BreakableObjects sont morts
    if (allDead) {
        std::cout << "Simulation Finished" << std::endl;
    }
}
