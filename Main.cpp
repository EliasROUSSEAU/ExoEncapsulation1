// ExerciceEncapsulation1.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "StaticObject.h"
#include "BreakableObject.h"
#include "Mob.h"
#include "Player.h"
#include "Vector2.h"
#include "World.h" // Ajoutez cette ligne pour inclure le fichier World.h

int main() {
    // Initialiser les objets
    StaticObject staticObj(1.0f, 2.0f);
    BreakableObject breakableObj(3.0f, 4.0f, 50.0f, 50.0f);
    Vector2 mobDirection(1.0f, 1.0f);
    Mob mob(5.0f, 6.0f, 40.0f, 40.0f, mobDirection, 0.3f);
    Vector2 playerDirection(0.5f, 0.5f);
    Player player(7.0f, 8.0f, 30.0f, 30.0f, playerDirection, 1.0f);

    // Tester les fonctions du StaticObject
    std::cout << "Testing StaticObject..." << std::endl;
    staticObj.SetXY(1.5f, 2.5f);

    // Tester les fonctions du BreakableObject
    std::cout << "\nTesting BreakableObject..." << std::endl;
    breakableObj.TakeDamage(20.0f);
    breakableObj.TakeDamage(40.0f); // Mort

    // Tester les fonctions du Mob
    std::cout << "\nTesting Mob..." << std::endl;
    mob.Deplacer();
    mob.TakeDamage(10.0f);
    mob.TakeDamage(50.0f); // Mort

    // Tester les fonctions du Player
    std::cout << "\nTesting Player..." << std::endl;
    player.Deplacer();
    player.TakeDamage(15.0f);
    player.TakeDamage(20.0f); // Mort
    player.Attack(&breakableObj); // Player attaque BreakableObject

    // Initialiser et exécuter le monde
    World world; // Crée une instance de World
    world.Init(); // Initialise les entités dans le monde

    // Exécute plusieurs étapes de simulation
    for (int i = 0; i < 10; ++i) { // Par exemple, simuler 10 étapes
        world.Step(); // Appelle la fonction Step pour chaque étape
    }

    return 0;
}

// Exécuter le programme : Ctrl+F5 ou menu Déboguer > Exécuter sans débogage
// Déboguer le programme : F5 ou menu Déboguer > Démarrer le débogage

// Astuces pour bien démarrer : 
//   1. Utilisez la fenêtre Explorateur de solutions pour ajouter des fichiers et les gérer.
//   2. Utilisez la fenêtre Team Explorer pour vous connecter au contrôle de code source.
//   3. Utilisez la fenêtre Sortie pour voir la sortie de la génération et d'autres messages.
//   4. Utilisez la fenêtre Liste d'erreurs pour voir les erreurs.
//   5. Accédez à Projet > Ajouter un nouvel élément pour créer des fichiers de code, ou à Projet > Ajouter un élément existant pour ajouter des fichiers de code existants au projet.
//   6. Pour rouvrir ce projet plus tard, accédez à Fichier > Ouvrir > Projet et sélectionnez le fichier .sln.
