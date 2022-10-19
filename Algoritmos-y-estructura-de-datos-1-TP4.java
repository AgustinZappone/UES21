public class Mergesort {
	
    /*
     Esta funcion mezcla 2 subarrays arr[]:
	 •El primer subarray es arr[1..m]
     •El segundo subarray es arr[m+1..r]
     
     */
	
    void mezclar(int arr[], int l, int m, int r){
        //Obtiene el tamaño de los 2 subarrays a ser mezclados
        int n1 = m - l + 1;
        int n2 = r - m;

        //Crea arrays temporales
        int L[] = new int[n1];
        int R[] = new int[n2];

        //Copia los datos a los arrays temporales
        for(int i = 0; i < n1;i++){
            L[i] = arr[l + i];
            for(int j = 0; j < n2;j++){
                R[j] = arr[m + 1 + j];
            }
        }

        //Mezcla los Arrays temporales

        //Indices iniciales del primer y segundo subarray
        int i = 0, j = 0;

        //Indices iniciales de los subarrays mezclados
        int k = l;
        while(i < n1 && j < n2){
            if(L[i] <= R[j]){
                arr[k] = L[i];
                i++;
            }else{
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        //Copiar los elementos pendientes de L[] si hay*
        while(i < n1){
            arr[k] = L[i];
            i++;
            k++;
        }

        //Copiar los elementos pendientes de R[] si hay
        while(j < n2){
            arr[k] = R[j];
            j++;
            k++;
        }

    }

    //Función principal que ordena arr[l..r] usando mezclar()
    void ordenar(int arr[], int l, int r){
    	
    	    	
        //Implementar metodo ordenar
        if(l < r){
            int mid = (l + r)/2;
            ordenar(arr, l, mid);
            ordenar(arr, mid + 1, r);
            mezclar(arr, l, mid, r);
            
            }

    }

}


public class Quicksort {

    /*
     
    Esta función toma el ultimo elemento como pivote,
    coloca el elemento pivote en su posición correcta en la matriz ordenada
    y coloca todos los elementos más pequeños(más pequeños que el pivite)
    a la izquierda del pivote y todos los elementos mayores a la derecha de
    pivote
    
    */

    int particion(int arr[], int low, int high){
        int pivot = arr[high];
        int i = (low -1); //indice del elemento mas chico
        for(int j = low; j < high; j++){
            //si el elemento actual es mas chico o igual que el pivot
            if(arr[j] <= pivot){
                i++;

                //swap arr[i] and arr[j]
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        //Intercambia arr[i + 1] y arr[high] (o pivot)
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;
        return i + 1;
    }


    /*
    
    Metodo principal que implementa quicksort
    arr[] --> Array a ser ordenado
    low   --> Comienzo de indice
    high  --> Fin de indice
    
    */
    void ordenar(int arr[], int low, int high){

        //Implementar metodo ordenar
        if(low < high){
            int p = particion(arr, low, high);
            ordenar(arr, low, p - 1);
            ordenar(arr, p + 1, high);
        }
    }

    
}

//Testeamos ambos metodos de ordenamiento en la clase Ordenar

import java.util.Arrays;

public class Ordenar {

    public static void main(String[] args) {
    	
        int arr[] = {1, 5, 3, 6, 2, 4};
        System.out.println("\nArray original antes de Mergesort \n" + Arrays.toString(arr));
        

        long timer1;
        long t1 = java.lang.System.nanoTime(); //obtiene el tiempo actual en nanosegundos antes de iniciar el método
        
        Mergesort obMS = new Mergesort();
        obMS.ordenar(arr,0,arr.length - 1);
        
        long t2 = java.lang.System.nanoTime(); //obtiene el tiempo actual en nanosegundos despues de finalizar el método
        
        timer1 = t2 - t1; //Obtenemos la diferencia entre el tiempo inicial y final para saber cuanto fue el tiempo que el metodo MERGESORT demoró
        
        System.out.println("\nArray ordenado por Mergesort \n" + Arrays.toString(arr)); //Imprime el Array ordenado en una misma linea
        System.out.println("Time: " + timer1 + " nanosegundos"); //Imprime el tiempo demorado

        int arr2[] = {1, 5, 3, 6, 2, 4};
        System.out.println("\nArray original antes de Quicksort \n" + Arrays.toString(arr2));
        
       
        long timer2;
        long t3 = java.lang.System.nanoTime(); //obtiene el tiempo actual en nanosegundos antes de iniciar el método
                
        int n = arr2.length;
        Quicksort obQS = new Quicksort();
        obQS.ordenar(arr2, 0, n -1);
        
        long t4 = java.lang.System.nanoTime();  //obtiene el tiempo actual en nanosegundos despues de finalizar el método
        
        timer2 = t4 - t3; //Obtenemos la diferencia entre el tiempo inicial y final para saber cuanto fue el tiempo que el metodo QUICKSORT demoró
        
                
        System.out.println("\nArray ordenado por Quicksort \n" + Arrays.toString(arr2)); //Imprime el Array ordenado en una misma linea
        System.out.println("Time: " + timer2 + " nanosegundos"); //Imprime el tiempo demorado


    }

}

