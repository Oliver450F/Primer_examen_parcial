#include <iostream>
#include <stdio.h>  
#include <string.h> 


using namespace std;


const char *nombe_archivo = "archivoo6.dat";

struct Empleado{
	int codigo;
	char nombre[55];
	char apellido[55];
	char puesto[55];
	int sueldo_base;
	int bonificacion;

	float net;
};
 void ingresar_empleado();
void abrir_empleado();
 void modificar_empleado();
 void eliminar_empleado();
int main (){
	abrir_empleado();
 ingresar_empleado();
	modificar_empleado();
	
	eliminar_empleado();
	return 0;	
}
void buscar_codigo(){
	
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int indice=0,pos=0,cod=0;
	cout<<"BUSCAR CODIGO: ";
	cin>>cod;
	Empleado empleado;
	
	fread ( &empleado, sizeof(empleado), 1, archivo );
		
		do{
			
			if (empleado.codigo == cod){
			pos = indice;
			}
	
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		indice += 1;
		} while (feof( archivo ) == 0);
		
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );

    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Puesto: " << empleado.puesto << endl;
          cout<< " Sueldo base :"<<empleado.sueldo_base<<endl;
          cout<< " Bonificacion :"<<empleado.bonificacion<<endl;
          cout<< " Sueldo neto: "<<empleado.net<<endl;
        
        cout << endl;
	
	fclose(archivo);
	system("PAUSE");
}


void buscar_indice(){
	FILE* archivo = fopen(nombe_archivo, "rb");
	
	int pos=0;
	cout<<"Que registro desea ver: ";
	cin>>pos;
	cout<<"------------------ "<<pos<<" ------------------"<<endl;
	fseek ( archivo,pos * sizeof(Empleado), SEEK_SET );
	
	Empleado empleado;
	
    fread ( &empleado, sizeof( Empleado ), 1, archivo );

    	cout << "Codigo: " << empleado.codigo << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Apellido: " << empleado.apellido << endl;
        cout << "Puesto: " << empleado.puesto << endl;
        cout<< " Sueldo base :"<<empleado.sueldo_base<<endl;
         cout<< " Bonificacion :"<<empleado.bonificacion<<endl;
         cout<< " Sueldo neto: "<<empleado.net<<endl;
      
        cout << endl;
	
	fclose(archivo);

	
}


void abrir_empleado(){

	system("cls");
	FILE* archivo = fopen(nombe_archivo, "rb");
	if(!archivo) {
		archivo = fopen(nombe_archivo, "w+b");
	}
	Empleado empleado;
	int registro=0;
	fread ( &empleado, sizeof(Empleado), 1, archivo );
	
	cout<<"________________________________________________________________________________________________________________________"<<endl;
	cout <<    " id "    <<"|"<< "   CODIGO    " <<"|"<< "       NOMBRE   "<<"      | "<<"     APELLIDO   "<<" "<<"     PUESTO   "<<" "<<"    SUELDO BASE    "<<" "<<" BONIFICACION"<< "  SUELDO NETO "<<endl;	
		do{
			empleado.net=0;
			empleado.net=empleado.sueldo_base+empleado.bonificacion;
		cout<<"________________________________________________________________________________________________________________________"<<endl; 
		cout << registro <<"   |     "<< empleado.codigo <<"      |    "<< empleado.nombre<<"   |  "<<empleado.apellido<<"         "<<empleado.puesto<<"         "<<empleado.sueldo_base<<"        "<<"       "<<empleado.bonificacion<<"       "<<empleado.net<<endl;
        
		fread ( &empleado, sizeof(Empleado), 1, archivo );
		registro += 1;	
		} while (feof( archivo ) == 0);
		
    cout<<endl;
    
		fclose(archivo);
	}
void ingresar_empleado(){
	
	char continuar;
	FILE* archivo = fopen(nombe_archivo, "ab"); // ab
	
	
		Empleado empleado;
		 string nombre,apellido,puesto;
		do{
			fflush(stdin);
			
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombres:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellidos:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
		cout<<"Ingrese el puesto:";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str());
		
			cout<<"Ingrese el sueldo base:";
		cin>>empleado.sueldo_base;
        cin.ignore();
        
        cout<<"Ingrese el Bonificacion :";
		cin>>empleado.bonificacion;
        cin.ignore();
       
        
      
		
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
		cout<<"Desea Agregar otro Nombres s/n : ";
		cin>>continuar;
		} while((continuar=='s') || (continuar=='S') );
		
	
	fclose(archivo);
	abrir_empleado();
	//buscar_indice();	
	buscar_codigo();
}
void modificar_empleado(){
	
	FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido,puesto;	
    	Empleado empleado;
    
		cout << "Ingrese el ID que desea Modificar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  // esto es lo que permite modificar en la pocision
	
		cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombres:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellidos:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
	cout<<"Ingrese el puesto:";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str()); 
		
			cout<<"Ingrese el sueldo base:";
		cin>>empleado.sueldo_base;
        cin.ignore();
        
        cout<<"Ingrese el Bonificacion :";
		cin>>empleado.bonificacion;
        cin.ignore();
        
	
		
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
	abrir_empleado();
		system("PAUSE");
}
void eliminar_empleado(){
	
FILE* archivo = fopen(nombe_archivo, "r+b");
	
		int id;
		string nombre,apellido,puesto;	
    	Empleado empleado;
    
		cout << "Ingrese el ID que desea elimiar: ";
    		cin >> id;
    		fseek ( archivo, id * sizeof(Empleado), SEEK_SET );  // esto es lo que permite modificar en la pocision

	
			cout<<"Ingrese el Codigo:";
		cin>>empleado.codigo;
        cin.ignore();
        
		cout<<"Ingrese el Nombres:";
		getline(cin,nombre);
    	strcpy(empleado.nombre, nombre.c_str()); 
			
		cout<<"Ingrese el Apellidos:";
		getline(cin,apellido);
		strcpy(empleado.apellido, apellido.c_str()); 
		
	cout<<"Ingrese el puesto:";
		getline(cin,puesto);
		strcpy(empleado.puesto, puesto.c_str()); 
		
			cout<<"Ingrese el sueldo base:";
		cin>>empleado.sueldo_base;
        cin.ignore();
        
        cout<<"Ingrese el Bonificacion :";
		cin>>empleado.bonificacion;
        cin.ignore();
        
	
		
			
		
		
		fwrite( &empleado, sizeof(Empleado), 1, archivo );
		
	fclose(archivo);
	abrir_empleado();
		system("PAUSE");
	

}
