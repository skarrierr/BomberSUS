// BomberSUS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>

float version = 0.0;
std::string title = "";
int totalTextures = 0;
std::map<std::string, std::string> textures;

int background_w = 0;
int background_h = 0;
std::string** background;

int foreground_w = 0;
int foreground_h = 0;
std::string** foreground;

int objects_w = 0;
int objects_h = 0;
std::string** objects;


int main()
{
    std::string temp;
    std::fstream file;

    file.open("level.sus", std::ifstream::in);

    if (!file.is_open()) {
        file.close();
        std::cout << "Error 1 : Couldn't open the file" << std::endl;
        return 1;
    }

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    if (temp != "SUS") {
        std::cout << "Error 2 : Incorrect format" << std::endl;
        return 2;
    }

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;

    version = std::stof(temp);

    std::getline(file, temp);

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    if (temp != "TITLE") {
        std::cout << "Error 3 : Title not found" << std::endl;
        return 3;
    }

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    if (temp == "") 
    {
        std::cout << "Error 4 : Title is empty" << std::endl;
        return 4;
    }
    else 
    {
        title = temp;
    }

    std::getline(file, temp);

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    if (temp != "TEXTURES") {
        std::cout << "Error 5 : Textures not found" << std::endl;
        return 5;
    }

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    totalTextures = std::stoi(temp);
    //std::cout << totalTextures << std::endl;
    std::getline(file, temp);



    for (size_t i = 0; i < totalTextures; i++)
    {
        std::string key;
        std::getline(file, key, ';');
        //std::cout << temp << std::endl;

        std::string value;
        std::getline(file, value, ';');
        //std::cout << temp << std::endl;

        textures.insert(std::pair<std::string, std::string>(key, value));
        std::cout << key << " : " << textures[key] << std::endl;

        std::getline(file, temp);
    }


    //BACKGROUND

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    if (temp != "BACKGROUND") {
        std::cout << "Error 6 : Background not found" << std::endl;
        return 6;
    }

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    background_w = std::stoi(temp);

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    background_h = std::stoi(temp);

    std::getline(file, temp);

    background = new std::string * [background_h];

    for (size_t i = 0; i < background_h; i++){
        background[i] = new std::string[background_w];
    }

    for (size_t i = 0; i < background_h; i++)
    {
        for (size_t j = 0; j < background_w; j++)
        {
            std::getline(file, temp, ';');
            background[i][j] = temp;
            std::cout << background[i][j] << " - ";
        }
        std::getline(file, temp);
        std::cout << std::endl;
    }

    //FOREGROUND

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    if (temp != "FOREGROUND") {
        std::cout << "Error 7 : Foreground not found" << std::endl;
        return 7;
    }

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    foreground_w = std::stoi(temp);

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    foreground_h = std::stoi(temp);

    std::getline(file, temp);

    foreground = new std::string * [foreground_h];

    for (size_t i = 0; i < foreground_h; i++) {
        foreground[i] = new std::string[foreground_w];
    }

    for (size_t i = 0; i < foreground_h; i++)
    {
        for (size_t j = 0; j < foreground_w; j++)
        {
            std::getline(file, temp, ';');
            foreground[i][j] = temp;
            std::cout << foreground[i][j] << " - ";
        }
        std::getline(file, temp);
        std::cout << std::endl;
    }

    //OBJECTS

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    if (temp != "OBJECTS") {
        std::cout << "Error 8 : Objects not found" << std::endl;
        return 8;
    }

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    objects_w = std::stoi(temp);

    std::getline(file, temp, ';');
    std::cout << temp << std::endl;
    objects_h = std::stoi(temp);

    std::getline(file, temp);

    objects = new std::string * [objects_h];

    for (size_t i = 0; i < objects_h; i++) {
        objects[i] = new std::string[objects_w];
    }

    for (size_t i = 0; i < objects_h; i++)
    {
        for (size_t j = 0; j < objects_w; j++)
        {
            std::getline(file, temp, ';');
            objects[i][j] = temp;
            if(j == objects_w-1){
                std::cout << objects[i][j];
            }
            else {
                std::cout << objects[i][j] << " - ";
            }
        }
        std::getline(file, temp);
        std::cout << std::endl;
    }


    return 0;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
