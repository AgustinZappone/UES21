
public class pila {
    
    class Nodo{
        int info;
        Nodo sig;
    }
    
    private Nodo raiz;
    
    public pila(){
        raiz=null;
    }
    
    public void apilar(int x){
        Nodo nuevo;
        nuevo = new Nodo();
        nuevo.info = x;
        
        if (raiz==null){
            nuevo.sig = null;
            raiz = nuevo;
        }
        else{
            nuevo.sig = raiz;
            raiz = nuevo;
        }
        
    }
    
    /*
    Es importante recordar el concepto de LIFO para codificar el método
    desapilar, ya que estaremos siempre trabajando con el tope de la pila,
    es decir, el ultimo elemento ingresado.
    */
    
    public int desapilar(){
        if (raiz!=null){
            int aux = raiz.info; //Almacenamos el valor de la raíz en una variable auxiliar
            raiz = raiz.sig; //Hacemos que la raiz tome el valor del siguiente elemento de la pila.
            return aux; //Retornamos el valor removido.
        }
        else{
            return Integer.MAX_VALUE; //Si la raiz es igual a null, quiere decir que la pila está vacía.
                                      //En este caso, retornamos el número entero máximo y lo tomamos como código de error
                                      //(es decir nunca debemos guardar el entero mayor en la pila).
        }
    }
    
    public void verContenido(){
        Nodo recorrer = raiz; //Creamos un puntero auxiliar que apunta al primer nodo de la lista
        
        if (recorrer == null){ //Si el puntero apunta a null, quiere decir que la pila está vacía. Lo señalamos
            System.out.println("La pila está vacía.");
        }
        else{ //Si la pila no esta vacía, procedemos...
        System.out.println("Listado de todos los elementos de la pila: ");
        
        //Recorremos cada nodo hasta que estemos apuntando a null (lo que indicará que llegamos al ultimo elemento).
        
        while  (recorrer!=null){ 
            System.out.print(recorrer.info + " - ");
            recorrer = recorrer.sig;
        }
        System.out.println();
        }
    }
    
    public static void main(String[] args){
        pila pila1 = new pila();
        pila1.apilar(10);
        pila1.apilar(40);
        pila1.apilar(3);
        pila1.verContenido();
        System.out.println("Cima de la pila es: "+pila1.desapilar());
        pila1.verContenido();
    }
    
}
