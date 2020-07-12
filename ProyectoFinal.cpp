#include "iostream"
#include "string.h"

const int longCad = 20;

using namespace std;

struct costoPorArticulo
{
    char nombreArticulo[longCad + 1];//nombre del articulo
    int cantidad;//cantidad de articulos
    float precio;//precio unitario del articulo
    float costoPorArticulo;
};

//Esta funcion lee los datos sobre el nombre, la cantidad y el precio unitario de cada articulo y los incorpora al arreglo producto[]
void leerArre(int n, costoPorArticulo producto[]);
//Est5a funcion sirve para calcular el costo por articulo e incorporar este valor en el campo producto[i].costoPorArticulo
void calculoC(int n, costoPorArticulo producto[]);
//esta funcion suma el costo de cada articulo y el valor se depliega en main
float facturaC(int n, costoPorArticulo producto[]);


int main(void)
{
    //variables
    int n;  //tamaño del arreglo
    float total;//cantidad de dinero a pagar
    
    //titulo del programa
    cout <<endl <<endl;
    cout << "\t|------------------" << " | " << "-----------------|" <<endl;
    cout << "\t|-- EL MERCADONA --" << " | " << "--   CAJA #1   --|" <<endl;
    cout << "\t|------------------" << " | " << "-----------------|" <<endl;
    cout <<endl <<endl;

    cout << "-Ingrese la cantidad de articulos diferentes: ";
    cin  >> n;
    costoPorArticulo  producto[n];
    cin.ignore(100, '\n');

    //Esta funcion lee los datos sobre el nombre, la cantidad y el precio unitario de cada articulo y los incorpora al arreglo producto[]
    leerArre(n, producto);

    //Est5a funcion sirve para calcular el costo por articulo e incorporar este valor en el campo producto[i].costoPorArticulo
    calculoC(n, producto);

    cout << "Esta es su cuenta: ";
    cout <<endl <<endl;

    //lista de los articulos con su respectivo precio y cantidad
    for(int i = 0; i < n; i++)
    {
        cout << "\t " << producto[i].cantidad << " " << producto[i].nombreArticulo << " a $";
        cout << producto[i].precio << " C/U son en total $" << producto[i].costoPorArticulo;
        cout <<endl;
    }

    //esta funcion suma el costo de cada articulo y el valor se depliega en main, guardando en dato en total
    total = facturaC(n, producto);

    // se despliaga el valor total a pagar
    cout << "------------------------------------------" <<endl;
    cout << "\tEl total a pagar es: $" << total <<endl;
    cout << "------------------------------------------" <<endl <<endl;

return 0;
}

//Esta funcion lee los datos sobre el nombre, la cantidad y el precio unitario de cada articulo y los incorpora al arreglo producto[]
void leerArre(int n, costoPorArticulo producto[])
{
    //variables
    string N_art;//nombre del articulo
    producto[n];

    cout << "--Ingrese el nombre, precio unitario y cantidad del articulo:" <<endl <<endl;
    
    //cada i sera un articulo y se complementaran sus datos en for
    for(int i = 0; i < n; i++)
    {
        bool rango = 1;

        cout <<"-Nombre: ";
        getline(cin, N_art, '\n');//se asigna el nombre del articulo
        strncpy(producto[i].nombreArticulo, N_art.c_str(), longCad);//el nombre dado se copia a el arreglo producto[], en el apartado de .nombreArticulo del articulo 
        producto[i].nombreArticulo[longCad] = '\0';//se establede el limite de la longitud del nombre del articulo, en 20 caracterres, siendo la posicion [20] = '\0'
        
        do
        {
            cout << "-Precio del articulo: $";
            cin  >> producto[i].precio;//se establede el precio del articulo en el arreglo producto[], en el apartado de .precio

            //si el precio es menor a un centavo el proceso se repite
            if(producto[i].precio < 0.01)
                rango = 0;
            
        }while(rango == 0);

        do
        {
            cout << "-Cantidad de articulos: ";
            cin  >> producto[i].cantidad;//se establede la cantidad del articulo en el arreglo producto[], en el apartado de .cantidad

            //si la cantidad ingresada es menor que uno y proceso se repite
            if(producto[i].cantidad < 1)
                rango = 0;

        }while(rango ==0);

        cin.ignore(100, '\n');
        cout <<endl;
    }

}

//Est5a funcion sirve para calcular el costo por articulo e incorporar este valor en el campo producto[i].costoPorArticulo
void calculoC(int n, costoPorArticulo producto[])
{
    //cada i sera un articulo
    for(int i = 0; i < n; i++)
    {
        // i vendira siendo cada tipo de artiiculo, multipicando en valor del articulo por la cantidad 
        producto[i].costoPorArticulo = producto[i].cantidad * producto[i].precio;
    }
}

//esta funcion suma el costo de cada articulo y el valor se depliega en main
float facturaC(int n, costoPorArticulo producto[])
{
    float total = 0;//iguala total a 0 ya que no se le a sumado nada

    for(int i = 0; i < n; i++)
    {
        //por cada iteracion se le suma el valor de costos de cada articulo se suma al total 
        total = total + producto[i].costoPorArticulo;
    }

    //cuando ya son sumados todos los articulos, el valor obtenido es retornado en la funcion main
    return total;
}