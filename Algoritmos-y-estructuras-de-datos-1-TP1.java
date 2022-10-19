public class Oficina{
    public int nro;
    public int piso;

    public int getNro() {
        return nro;
    }

    public int getPiso() {
        return piso;
    }
 
    //public oficina encontrarPrimeraOficinaActiva();

    public void setNro(int nro) {
        this.nro = nro;
    }

    public void setPiso(int piso) {
        this.piso = piso;
    }
            
}



public class Edificio {
    private int numOficinasPorPiso = 9; //Para los propositos del TP, contamos al como oficina, porque tiene sensor.
    private double superficie;
    private int numPisos = 10; //Debido a que Planta Baja no tiene sensores, solo contamos los 10 pisos que tiene encima.
    private int numOficinas = numOficinasPorPiso * numPisos;
    boolean Oficinas[][] = new boolean [numPisos][numOficinasPorPiso]; //Esta matriz permite ubicar cada una de las oficinas por piso y numero de oficina.
    
    
       
    /*
    METODO OBTENERSENSOR
    
    Este método pide dos parámetros (piso y oficina). Devuelve un boolean acorde a si 
    hay personas (True) o no (False).
    
    */
   
    
    public boolean obtenerSensor(int piso, int oficina){
        boolean Activo = false;
        if (piso > 0 && piso <= numPisos && oficina > 0 && oficina <= numOficinasPorPiso){
            Activo = Oficinas[piso][oficina];
            
        }
        return Activo;
    }
    
    /*
    METODO CANTIDADOFICINASACTIVAS
    
    Este método recorre todas las oficinas del edificio y cuenta cuales oficinas están activas.
    Devuelve al final la suma de todas las oficinas activas.
    
    */
    
    public int cantidadOficinasActivas(){
        int i, j, count = 0;
        boolean estado = false;
        for(i=1;i<numPisos;i++){
            for(j=1;j<numOficinasPorPiso;j++){
                estado = Oficinas[i][j];
                if (estado = true){
                    count++;
                }
            }            
        }
        return count;
    }    
    
    
    
    public int getNumOficinasPorPiso() {
        return numOficinasPorPiso;
    }

    public int getNumPisos() {
        return numPisos;
    }

    /*
    METODO ENCONTRARPRIMERAOFICINAACTIVA
    
    Recorre todas las oficinas del edificio (arrancando por piso 1, oficina 1),
    y continua hasta encontrar una oficina activa.
    Al encontrar una activa, rompe el bucle y devuelve esa oficina.
    
    */
    
    public Oficina encontrarPrimeraOficinaActiva(){
        int i, j;
        boolean estado = false;
        Oficina activa = null;
        outerloop:
            for(i=1;i<numPisos;i++){
                for(j=1;j<numOficinasPorPiso;j++){
                    estado = Oficinas[i][j];
                    if (estado = true){
                        activa.setPiso(i);
                        activa.setNro(j);
                        System.out.print("La primera oficina activa es: Oficina "+ activa.piso + "." + activa.nro);
                    
                        break outerloop;
                    
                    
                                        
                    }
                    else{
                        System.out.print("Ninguna oficina esta activa.");
                    }
                }
        }
    return activa;
        
    
    
    }
}


//Usamos la clase main para testear


import java.util.Scanner;

public class main {
    public static void main (String[] args){
        
        Scanner entrada = new Scanner(System.in);
        System.out.print("Para inicializar el programa, indique para cada oficina mencionada si la misma esta activa: \n\n");
        
        Edificio building = new Edificio();
         
         
         /*
          Me pareció que lo mas lógico para este TP, sería crear un objeto de clase Oficina por
          cada oficina. Pero para eso, cada oficina tiene que tener un nombre diferente. Por lo que
          deberían llamarse office1,office2,office3,etc.
          No entoncré forma de crear variables de nombre dinámico, por lo que creo que es mas razonable
          una matriz dentro de la clase Edificio que una clase Oficina por separado.
        
         int a, b;
         for(a=1;a<(building.getNumPisos());a++){
            for(b=1;b<(building.getNumOficinasPorPiso());b++){
                Oficina office = new Oficina();
                }            
        }
        */

        
        int i, j, piso, oficina;
        
        for(i=1;i<(building.getNumPisos());i++){
            for(j=1;j<(building.getNumOficinasPorPiso());j++){
                System.out.print("Oficina ["+i+"]["+j+"]: ");
                building.Oficinas[i][j] = entrada.nextBoolean();
                
                }
        
        }
        System.out.print("\n\nIngrese piso y numero de la oficina que quiere saber si está activa: \n");
        System.out.print("N° piso: ");
        piso = entrada.nextInt();
        System.out.print("\nN° oficina: ");
        oficina = entrada.nextInt();
        
        boolean Respuesta = building.obtenerSensor(piso, oficina);
        System.out.print("\n\nOficina activa: "+Respuesta);
    }
}    

    

        
    



