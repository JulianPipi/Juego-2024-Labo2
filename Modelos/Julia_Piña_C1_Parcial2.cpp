#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;
#include "parcial2.h"

class ProveedorSinCompras
{
private:
    int ProvProv,NroDeProv;
    char NombDeProv[30];

public:
    void setNombProv(const char *N)
    {
        strcpy(NombDeProv,N);
    }
    void setNroDeProv(int Nro)
    {
        NroDeProv=Nro;
    }
    void setProvProv(int P)
    {
        ProvProv=P;
    }

    void Mostrar()
    {
        cout<<NroDeProv<<endl;
        cout<<NombDeProv<<endl;
        cout<<ProvProv<<endl;
    }
};

class ArchivoProveedorSinCompras
{
private:
    char Nombre[30];
public:
    ArchivoProveedorSinCompras(const char *N)
    {
        strcpy(Nombre,N);
    }

    ProveedorSinCompras leerRegistro(int pos)
    {
        ProveedorSinCompras reg;
        FILE *p=fopen(Nombre,"rb");
        if(p==NULL)
        {
            return reg;
        }
        fseek(p, pos * sizeof reg, 0);
        fread(&reg, sizeof reg, 1, p);
        fclose(p);
        return reg;
    }
    int contarRegistros()
    {
        FILE *p=fopen(Nombre,"rb");
        if(p==NULL)
        {
            return -1;
        }
        fseek(p, 0, 2);
        int cant=ftell(p)/sizeof(ProveedorSinCompras);
        fclose(p);
        return cant;
    }
    bool grabarRegistro(ProveedorSinCompras reg)
    {
        FILE *p;
        p=fopen(Nombre, "ab");
        if(p==NULL) return false;
        int escribio=fwrite(&reg, sizeof reg,1, p);
        fclose(p);
        return escribio;
    }

void listarArchivo(){
FILE *p = fopen(Nombre, "rb");
        if (p == NULL) {
            cout << "No se pudo abrir el archivo." << endl;
            return;
        }
        ProveedorSinCompras reg;
        while (fread(&reg, sizeof reg, 1, p) == 1) {
            reg.Mostrar();
        }
        fclose(p);
    }

};
void Punto1()
    {
        ArchivoCompras Comp("compras.dat");
        ArchivoProveedorSinCompras Obj("Punto1.dat");
        ArchivoProveedores Prov("proveedores.dat");
        ProveedorSinCompras Aux;
        Proveedor Obj_Provedor;
        Compra obj_Compra;
        bool TuvoCompras=false;
        int CantRegProv,CantRegCom;
        CantRegProv=Prov.contarRegistros();
        CantRegCom=Comp.contarRegistros();
        for(int i=0; i<CantRegProv; i++)
        {
            Obj_Provedor=Prov.leerRegistro(i);
            for(int x=0;x<CantRegCom;x++)
            {
            obj_Compra=Comp.leerRegistro(x);

            if(obj_Compra.getNumeroproveedor()==Obj_Provedor.getNumeroProveedor() && obj_Compra.getFechaCompra().getAnio()==2024){
               TuvoCompras=true;
            }
            }

        if(TuvoCompras==false){
             Aux.setNombProv(Obj_Provedor.getNombre());
                Aux.setNroDeProv(Obj_Provedor.getNumeroProveedor());
                Aux.setProvProv(Obj_Provedor.getProvincia());
                Obj.grabarRegistro(Aux);
                  }
        }
        Obj.listarArchivo();

    }

void Punto_2()
{
    Material obj_mat;
    ArchivoMateriales arc_mat("materiales.dat");
    int cant=arc_mat.contarRegistros();
    int v_tip[6]={};
    int menor_tipo=0;
    bool primero=false;
    for(int i=0;i<cant;i++)
    {
        obj_mat=arc_mat.leerRegistro(i);
        v_tip[obj_mat.getTipo()]++;
    }
    for(int i=0;i<6;i++)
    {
        if(v_tip[i]>0)
        {
            if(primero==false)
            {
                menor_tipo=i+1;
                primero=true;
            }
            else
            {
                if(v_tip[menor_tipo]>v_tip[i])
                {
                    menor_tipo=i+1;
                }
            }
        }
    }
    cout<<"El tipo de material con menos cantidad de materiales es el tipo: "<<menor_tipo<<endl;
    system("pause");
}

int main()
{
/* int opc=-1;
    while(true)
    {
        cout<<"------------MENU PRINCIPAL------------"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"1 - PUNTO A"<<endl;
        cout<<"2 - PUNTO B"<<endl;
        cout<<"3 - PUNTO C"<<endl;
        cout<<"4 - PUNTO D"<<endl;
        cout<<"5 - PUNTO E"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"6 - SALIR"<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<"INGRESE UNA OPCION ";
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            Punto1();
            break;
        case 2:
            Punto_2();
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            cout<<"OPCION INVALIDA"<<endl;
        }
        system("pause");
        system("cls");
    }

*/
  Punto_2();


    return 0;
}
