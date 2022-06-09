// ZAP613_Practica10_BattleRoyale.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//Josue Rafael Cruz Poceros

#include <iostream>
#include <cstdlib>
#include <string>
#include <Windows.h>

struct Personas 
{
    std::string nom;
    int vida, defensa, ataque, inteligencia;
}persona[10];

void gotoxy(int x, int y) 
{
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void stats() 
{
    for (int i = 0; i < sizeof(persona) / sizeof(persona[i]); i++) {
        std::cout << "Nombre de la persona " << i + 1 << " : ";
        std::getline(std::cin, persona[i].nom);
        std::cout << std::endl;
        persona[i].vida = rand() % 20;
        Sleep(1000);
        std::cout << "La vida de " << persona[i].nom << " es: " << persona[i].vida << "\n";
        persona[i].defensa = rand() % 20;
        
        Sleep(1000);
        std::cout << "La defensa de " << persona[i].nom << " es: " << persona[i].defensa << "\n";
        if (persona[i].defensa <= 5)
        {
            Sleep(1000);
            std::cout << "Una armadura no caeria mal.\n";
        }
        else
        {
            Sleep(1000);
            std::cout << "Vaya tanque.\n";
        }
        persona[i].ataque = rand() % 20;
        Sleep(1000);
        std::cout << "El ataque de " << persona[i].nom << " es: " << persona[i].ataque << "\n";
        if (persona[i].ataque <= 5)
        {
            Sleep(1000);
            std::cout << "Dedicale unas horas al gym, bro.\n";
        }
        else
        {
            Sleep(1000);
            std::cout << "Que mamado esta el caon.\n";
        }
        persona[i].inteligencia = rand() % 20;
        Sleep(1000);
        std::cout << "La inteligencia de " << persona[i].nom << " es: " << persona[i].inteligencia << "\n";
        if (persona[i].inteligencia <= 5)
        {
            Sleep(1000);
            std::cout << "Hay que estudiar mas.\n";
        }
        else
        {
            Sleep(1000);
            std::cout << "Tenemos un genio aqui.\n";
        }
        system("pause");
        system("CLS");
    }
}

void Maximo() 
{
    int maxVida, maxDefensa, maxAtaque, maxInteligencia;
    for (int i = 0; i < sizeof(persona) / sizeof(persona[i]); i++) {
        if (i == 0) {
            maxVida = i;
        }
        else
        {
            if (persona[i].vida > persona[i - 1].vida) {
                maxVida = i;
            }
        }
        if (i == 0) {
            maxVida = i;
        }
        else
        {
            if (persona[i].defensa > persona[i - 1].defensa) {
                maxDefensa = i;
            }
        }
        if (i == 0) {
            maxAtaque = i;
        }
        else
        {
            if (persona[i].ataque > persona[i - 1].ataque) {
                maxAtaque = i;
            }
        }
        if (i == 0) {
            maxInteligencia = i;
        }
        else
        {
            if (persona[i].inteligencia > persona[i - 1].inteligencia) {
                maxInteligencia = i;
            }
        }
    }

    std::cout << persona[maxVida].nom << " es la persona con mas saludable. Tiene " << persona[maxVida].vida <<" puntos de vida" << "\n";
    Sleep(1000);
    std::cout << persona[maxDefensa].nom << " es el/la tanque con " << persona[maxDefensa].defensa <<" puntos de defensa" << "\n";
    Sleep(1000);
    std::cout << persona[maxAtaque].nom << " es la persona con mas mamada. Tiene " << persona[maxAtaque].ataque <<" puntos de ataque" << "\n";
    Sleep(1000);
    std::cout << persona[maxInteligencia].nom << " es la persona mas inteligente: " << persona[maxInteligencia].inteligencia << "\n";
    Sleep(1000);
    system("pause");
    system("CLS");
}


int main()
{
    int perat = 0, perdef = 0;
    int atacante, defensor;
    bool repetir = true;
    do
    {
        std::cout << "Bienvenido!\n";
        Sleep(1600);
        std::cout << "Los estudiantes de DSI pelearan en un battle royale.\n";
        Sleep(1600);
        std::cout<<"La ultima persona de pie sera el vencedor\n";
        Sleep(1600);
        system("pause");
        system("CLS");
        stats();
        Maximo();

        while (perdef < 7) {
            atacante = 0;
            defensor = 0;
            perdef++;
            if (persona[perat].vida < persona[perdef].vida) {
                defensor++;
            }
            else {
                atacante++;
            }
            if (persona[perat].defensa < persona[perdef].defensa) {
                defensor++;
            }
            else {
                atacante++;
            }
            if (persona[perat].ataque < persona[perdef].ataque) {
                defensor++;
            }
            else {
                atacante++;
            }
            if (persona[perat].inteligencia < persona[perdef].inteligencia) {
                defensor++;
            }
            else {
                atacante++;
            }
            if (atacante > defensor) {
                continue;
            }
            else {
                perat = perdef;
                continue;
            }

        }
        std::cout << "El ganador es:\n";
        Sleep(1900);
        gotoxy(50, 10);
        std::cout << persona[perat].nom<<"\n";
        Sleep(2000);

        std::cout << "Si quieres repetir la batalla presiona 1\nSi quieres salir del programa presiona 0\n";
        std::cin>>repetir;
    } while (repetir == true);
    
}
