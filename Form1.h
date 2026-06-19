#pragma once
#include "sprites.h"
#include "funciones.h"
namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    private:
        IContainer^ components;
        Timer^ bucle;

        sprites^ gestor;
        funciones^ funcion;
        int pantalla;
    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }
        }
    public:
        Form1(void)
        {
            InitializeComponent();

            WindowState = FormWindowState::Maximized;
            DoubleBuffered = true;
            pantalla = 0;

            gestor = gcnew sprites();
            gestor->hacer_sprites();

            funcion = gcnew funciones(gestor);
            funcion->asignar_propiedades();

            funcion->mostrar_volver(false);

            this->Controls->Add(funcion->b_jugar);
            this->Controls->Add(funcion->b_opciones);
            this->Controls->Add(funcion->b_creditos);
            this->Controls->Add(funcion->b_tienda);
            this->Controls->Add(funcion->b_salir);
            this->Controls->Add(funcion->b_volver);

            funcion->b_jugar->Click += gcnew EventHandler(this, &Form1::jugar);
            funcion->b_opciones->Click += gcnew EventHandler(this, &Form1::opciones);
            funcion->b_creditos->Click += gcnew EventHandler(this, &Form1::creditos);
            funcion->b_tienda->Click += gcnew EventHandler(this, &Form1::tienda);
            funcion->b_salir->Click += gcnew EventHandler(this, &Form1::salir);
            funcion->b_volver->Click += gcnew EventHandler(this, &Form1::volver);

            bucle->Tick += gcnew System::EventHandler(this, &Form1::bucle_Tick);

            this->MouseMove += gcnew MouseEventHandler(this, &Form1::OnMouseMove);
            this->MouseClick += gcnew MouseEventHandler(this, &Form1::OnMouseClick);
            this->Activated += gcnew EventHandler(this, &Form1::OnActivated);
        }

        virtual void OnPaint(PaintEventArgs^ e) override
        {
            Form::OnPaint(e);
            e->Graphics->InterpolationMode = Drawing2D::InterpolationMode::NearestNeighbor;
            if (pantalla == 0) {
                funcion->dibujar_fondo_inicial(e->Graphics);
            }
            if (pantalla == 1) {
                funcion->dibujar_tienda(e->Graphics);
            }
        }

    private:
        void jugar(Object^ sender, EventArgs^ e)
        {
            pantalla = 1;
            funcion->mostrar_opciones_menu(false);
            funcion->mostrar_volver(true);
            Invalidate();
        }

        void opciones(Object^ sender, EventArgs^ e)
        {
            pantalla = 2;
            funcion->mostrar_opciones_menu(false);
            funcion->mostrar_volver(true);
            Invalidate();
        }

        void creditos(Object^ sender, EventArgs^ e)
        {
            pantalla = 3;
            funcion->mostrar_opciones_menu(false);
            funcion->mostrar_volver(true);
            Invalidate();
        }

        void tienda(Object^ sender, EventArgs^ e)
        {
            pantalla = 4;
            funcion->mostrar_opciones_menu(false);
            funcion->mostrar_volver(true);
            funcion->mostrar_tienda(true);
            Invalidate();
        }

        void salir(Object^ sender, EventArgs^ e)
        {
            Application::Exit();
        }

        void volver(Object^ sender, EventArgs^ e)
        {
            funcion->mostrar_opciones_menu(true);
            funcion->mostrar_tienda(false);
            funcion->mostrar_volver(false);
            pantalla = 0;
            Invalidate();
        }

        void OnActivated(Object^ sender, EventArgs^ e) {}
        void OnMouseMove(Object^ sender, MouseEventArgs^ e) {}
        void OnMouseClick(Object^ sender, MouseEventArgs^ e) {}

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->components = (gcnew System::ComponentModel::Container());
            this->bucle = (gcnew System::Windows::Forms::Timer(this->components));
            this->SuspendLayout();

            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
                static_cast<System::Int32>(static_cast<System::Byte>(128)));
            this->Name = L"Form1";
            this->Text = L"Form1";

            this->bucle->Interval = 16;
            this->bucle->Enabled = true;

            this->ResumeLayout(false);
        }
#pragma endregion
    private: System::Void bucle_Tick(System::Object^ sender, System::EventArgs^ e) {
        Invalidate();
    }
    };
}
