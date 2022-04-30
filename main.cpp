#include<iostream>
#include<fstream>
using namespace std;
int **matrix_calificaciones;
string *names_person;
string *names_movie;
// int matrix[25];


void create_matrix_califications_dinamic(int** & matrix_input,int num_peliculas,int num_personas ){
    matrix_input=new int*[num_peliculas];
    for(int i=0;i<num_peliculas;i++){
        matrix_input[i]=new int[num_personas];
    }
}
void llenar_matrix_califications(){
    string texto;//CREAMOS LA VARIABLE Q USAREMOS PARA CREAR NUESTRA MATRIZ
    create_matrix_califications_dinamic(matrix_calificaciones,25,25);//CREAMOS LA MATRIZ
    string texto_it_aux;
    ifstream archivo;//DECLARACION  DE LA VARIABLE DE TIPO IFSTREAM Q LEERA NUESTRO CSV
    archivo.open("Movie_Ratings.csv",ios::in);//ABRE EL ARCHIVO TXT O LO  GENERA DE NO EXISTIR

    //CONDICION PARA MOSTRARNOS ERROR EN CASO DE NO ABRIR EL ARCHIVO
    if(archivo.fail()){
        cout<<"Error al abrir archivo"<<endl;
        exit(1);//PARA SALIR DEL PROGRAMA
    }
    int orden_fila=0;
    getline(archivo,texto_it_aux);//CON ESTE GETLINE OMITIMOS LA PRRIMERA LINEA
    while(!archivo.eof()){
        
        getline(archivo,texto_it_aux);
        int i;//
        for(i=0;i<texto_it_aux.size();i++){//ESTE  BUCLE NOS PERMITE OMITIR LOS NOMBRES DE LAS MOVIES
            if(texto_it_aux[i]==',')break;
        }
        for(;i<texto_it_aux.size();i++){
            texto+=texto_it_aux[i];
        }        
        //FRAGMENTO DE ALGORITMO  PARA LLENAR NUESTRA MATRIZ DE CALIFICACION

        
        int orden_col=0;
        for(int i=0;i<texto.size();i++){
            if(texto[i]==','){
                if(texto[i+1]==',' ||texto[i+1]=='\0'){
                    matrix_calificaciones[orden_fila][orden_col]=-1;
                    
                }
                else matrix_calificaciones[orden_fila][orden_col]=((int)texto[i+1])-48;
                orden_col++;

                
            }
        }
        orden_fila++;
        texto="";//LIMPIAMOS  EL TEXTO DEL MOMENTO
        

    }
    
    archivo.close();//SE CIERRA EL ARCHIVO
    

}
int consultar_nota(int ID_persona,int ID_movie){
    return matrix_calificaciones[ID_movie-1][ID_persona-1];
}
// void escribir_csv(){
//     string aux="";
//     ofstream archivo;//DECLARACION  DE LA VARIABLE DE TIPO OFSTREAM QUE GENERARA Y ESCRIBIRA UN TXT
//     archivo.open("participantes.csv",ios::out);//ABRE EL ARCHIVO TXT O LO  GENERA DE NO EXISTIR

//     //CONDICION PARA MOSTRARNOS ERROR EN CASO DE NO ABRIR EL ARCHIVO
//     if(archivo.fail()){
//         cout<<"Error al abrir archivo"<<endl;
//         exit(1);//PARA SALIR DEL PROGRAMA
//     }

//     //ESCRIBIMOS Eje X en la primera linea
//     archivo<<"'nombre'"<<'\n';//ESCRIBIMOS EN EL TEXTO DOS COLUMNAS LA SEGUNDA ES DE AUXILIAR

//     //BUCLE FOR QUE ESCRIBIRA LAS LONGITUDES DE LOS ARREGLOS EN EL ARCHIVO
//     for(int i=0;i<texto.size();i++){
//         // if(texto[i]!='"' && texto[i]!=',')aux+=texto[i];
//         // else aux+='';
//         if (texto[i]=='"')archivo<<"'";
//         else if( texto[i]!=',')archivo<<texto[i];//ESTE PARTE ESCRIBE EN EL CSV LO Q SEAA TEXTO NO , O ""
        
//         else if(texto[i]==',') archivo<<'\n';//EN ESTA PARTE HACEMOS EL SALTO DE LINEA
//     }
//     // cout<<aux;
//     // archivo<<aux;
//     archivo.close();//SE CIERRA EL ARCHIVO
// }
int main(){


    llenar_matrix_califications();
    int dim_1=25;
    int dim_2=25;

    

    // for(int i=0;i<dim_1;i++){
    //     for(int j=0;j<dim_2;j++){
    //         cout<<matrix_calificaciones[i][j]<<"->";
    //     }
    //     cout<<endl;
    // }
    cout<<consultar_nota(7,18);
    return 0;
}