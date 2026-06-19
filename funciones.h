#pragma once
#include "variables.h"
#include "entidades.h"
#include "sprites.h"
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;
using namespace std;
using namespace System::Collections::Generic;

public ref class funciones {
private:

    sprites^ s;

    void propiedades(Button^ b, String^ nombre, int id)
    {
        b->BackColor = SystemColors::InactiveCaption;
        b->FlatAppearance->BorderColor = Color::Navy;
        b->FlatAppearance->BorderSize = (float)grosor * 0.18;
        b->FlatStyle = FlatStyle::Flat;
        b->Font = gcnew Drawing::Font(L"Gill Sans Ultra Bold", (float)grosor / 2.5, FontStyle::Regular, GraphicsUnit::Point, static_cast<System::Byte>(0));
        b->Text = nombre;
        b->TabIndex = id;
        b->UseVisualStyleBackColor = true;
    }
public:

    funciones(sprites^ _s) {
        s = _s;
    }

    Button^ b_jugar = gcnew Button();
    Button^ b_opciones = gcnew Button();
    Button^ b_creditos = gcnew Button();
    Button^ b_tienda = gcnew Button();
    Button^ b_salir = gcnew Button();
    Button^ b_personalizacion = gcnew Button();
    Button^ b_volver = gcnew Button();
    Button^ b_nivel_1 = gcnew Button();
    Button^ b_nivel_2 = gcnew Button();
    Button^ b_nivel_3 = gcnew Button();
    Button^ b_nivel_4 = gcnew Button();
    Button^ b_vida = gcnew Button();
    Button^ b_velocidad = gcnew Button();

    void boton_volver() {
        b_volver->Size = Drawing::Size(6 * grosor, (float)1.8 * grosor);
        b_volver->Location = Point(0, 0);

        propiedades(b_volver, L"Volver", 6);

        b_volver->FlatStyle = FlatStyle::Flat;

        b_volver->Font = gcnew Drawing::Font(L"Gill Sans Ultra Bold", (float)grosor / 2.5, FontStyle::Regular, GraphicsUnit::Point, static_cast<System::Byte>(0));
        b_volver->Text = "volver";
        b_volver->TabIndex = 6;
        b_volver->UseVisualStyleBackColor = true;

        b_volver->BackColor = SystemColors::ControlText;
        b_volver->FlatAppearance->BorderColor = Color::AliceBlue;
        b_volver->ForeColor = Color::AliceBlue;
    }

    void botones_menu() {

        int mitad = ancho / 2;
        int y = alto * 0.5;

        b_jugar->Size = Drawing::Size(13 * grosor, 2 * grosor);
        b_opciones->Size = Drawing::Size(6 * grosor, 2 * grosor);
        b_creditos->Size = Drawing::Size(6 * grosor, 2 * grosor);
        b_tienda->Size = Drawing::Size(13 * grosor, 2 * grosor);
        b_salir->Size = Drawing::Size(13 * grosor, 2 * grosor);
        b_personalizacion->Size = Drawing::Size(13 * grosor, 2 * grosor);

        propiedades(b_jugar, L"jugar", 0);
        propiedades(b_opciones, L"opciones", 1);
        propiedades(b_creditos, L"creditos", 2);
        propiedades(b_tienda, L"tienda", 3);
        propiedades(b_salir, L"salir", 4);
        propiedades(b_personalizacion, L"Personaje", 5);

        b_jugar->Location = Point(mitad - b_jugar->Width / 2, y);
        b_opciones->Location = Point(mitad - b_jugar->Width / 2, y + grosor * 3);
        b_creditos->Location = Point(mitad + grosor / 2, y + grosor * 3);
        b_tienda->Location = Point(mitad - b_tienda->Width / 2, y + grosor * 6);
        b_salir->Location = Point(mitad - b_salir->Width / 2, y + grosor * 9);

    }

    void botones_tienda() {

        int mitad = ancho / 2;

        b_vida->Size = Drawing::Size(4 * grosor, 4 * grosor);
        b_velocidad->Size = Drawing::Size(4 * grosor, 4 * grosor);

        propiedades(b_jugar, L"jugar", 7);
        propiedades(b_opciones, L"opciones", 8);

        b_vida->Location = Point(mitad - b_vida->Width / 4, 1);
        b_velocidad->Location = Point(mitad - b_velocidad->Width / 2, 1);

    }

    void asignar_propiedades() {
        boton_volver();
        botones_menu();
        botones_tienda();
    }

    void mostrar_opciones_menu(bool visible)
    {
        b_jugar->Visible = visible;
        b_opciones->Visible = visible;
        b_creditos->Visible = visible;
        b_tienda->Visible = visible;
        b_salir->Visible = visible;
    }

    void mostrar_tienda(bool visible)
    {
        b_vida->Visible = visible;
        b_velocidad->Visible = visible;
    }

    void mostrar_volver(bool visible)
    {
        b_volver->Visible = visible;
    }

    void dibujar_fondo_inicial(Graphics^ g)
    {
        String^ ruta = System::Windows::Forms::Application::StartupPath + "\\Recursos\\Menu.png";
        try {
            Bitmap^ img_fondo = gcnew Bitmap(ruta);
            g->DrawImage(img_fondo, 0, 0, 1376, 768);
            delete img_fondo;
        }
        catch (Exception^ e) {
            g->Clear(Color::DarkGray);
            System::Drawing::Font^ f_error = gcnew System::Drawing::Font("Arial", 14);
            g->DrawString("Error: " + e->Message, f_error, Brushes::White, 50, 50);
            g->DrawString("Ruta: " + ruta, f_error, Brushes::White, 50, 100);
        }
    }
    void dibujar_tienda(Graphics^ g)
    {
        s->dibujar(550, 350, OBJETOS, 0, g);
    }
};
