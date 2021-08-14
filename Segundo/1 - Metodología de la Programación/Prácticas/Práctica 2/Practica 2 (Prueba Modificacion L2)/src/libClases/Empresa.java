package libClases;
import java.util.Scanner;

public class Empresa implements Cloneable, Proceso {

	private Cliente[] clientes;
	private int nClientes;
	private final int Incremento = 2;
	
	public Empresa() {
		this.clientes=new Cliente[Incremento];
		this.nClientes=0;
	}
	
	
	public int buscarCliente(String nifBuscar) {
		boolean encontrado=false;
		int i=0;
		while(i<nClientes && encontrado==false) {
			if(clientes[i].getNif().equals(nifBuscar))
				encontrado=true;
			else
				i++;
		}
		if(encontrado)
			return i;
		else
			return -1;
	}
	

 	public void alta(Cliente c) {
 		int pertenece = buscarCliente(c.getNif());
 		if (pertenece!=-1) {
 			System.out.println("Ya existe un cliente con ese NIF.");
 		}
 		else {
 			clientes[nClientes++]=c;
 			if (nClientes == clientes.length) {
 				Cliente [] tmp = new Cliente[clientes.length+Incremento];
 				for (int i=0; i<clientes.length; i++) {
 					tmp[i]=clientes[i];
 				}
 				clientes=tmp;
 			}
 		}
 	}


	public void alta() {
		Cliente cli;
		String NIF, nombre;
		Fecha fNac, fAlta;
		float minHab;
		Scanner s = new Scanner (System.in);
		
		System.out.println("Introduce el DNI: ");
		NIF=s.nextLine();
		
		int posBuscar = buscarCliente(NIF);
		if (posBuscar != -1) {
			System.out.println("Ya existe un cliente con ese DNI");
		}
		else {
			System.out.println("Nombre: ");
			nombre=s.nextLine();
			System.out.println("Fecha de Nacimiento: ");
			fNac=Fecha.pedirFecha();
			System.out.println("Fecha de Alta: ");
			fAlta=Fecha.pedirFecha();
			System.out.println("Minutos hablados: ");
			minHab = s.nextFloat();
			
			System.out.println("Indique el tipo de cliente: 1-Movil,  2-TarifaPlana");
			if(s.nextInt()==1) {
				float pMinuto;
				Fecha fPerm;
				System.out.print("Precio por minuto: ");
                pMinuto = s.nextFloat();
                System.out.println("Fecha fin permanencia:");
                fPerm = Fecha.pedirFecha();

                cli = new ClienteMovil(NIF, nombre, fNac, fAlta, fPerm, minHab, pMinuto);
            }else{
                String nacionalidad;
                System.out.print("Nacionalidad: ");
                nacionalidad = s.nextLine();

                cli = new ClienteTarifaPlana(NIF, nombre, fNac, fAlta, minHab, nacionalidad);
            }

            alta(cli);
        }
	}
		
	
	
	@Override
	public void ver() {
		System.out.println(this);
	}


	public void baja(String nif) {
        int pos = buscarCliente(nif);
        if(pos != -1){
            for(int i = pos; i < nClientes-1; i++)
                clientes[i] = clientes[i+1];
            nClientes--;
        }
        if(nClientes < clientes.length - Incremento){
            Cliente[] tmp = new Cliente[clientes.length-Incremento];
            for(int i = 0; i < tmp.length; i++)
                tmp[i] = clientes[i];
            clientes = tmp;
        }
	}


	public void baja() {
        Scanner s = new Scanner(System.in);
        
        System.out.print("Introduzca nif cliente a dar de baja: ");
        int pos = buscarCliente(s.nextLine());
        if(pos == -1)
            System.out.println("No se ha encontrado el cliente.");
        else{
            Cliente c = clientes[pos];
            System.out.println(c);
            System.out.print("¿Seguro que desea eliminarlo (s/n)? ");
            if(s.nextLine().equals("s")){
                baja(c.getNif());
                System.out.println("El cliente "+c.getNombre()+" con nif "+c.getNif()+" ha sido eliminado.\n");
            }else{
                System.out.println("El cliente con nif "+c.getNif()+" no se elimina.\n");
            }
        }
	}


	public float factura() {
        float factura = 0;
        
        for(int i = 0; i  < nClientes; i++)
            factura += clientes[i].factura();
        
        return factura;
	}


	public void descuento(int desc) {
        float descuento = (float)((100-desc))/100.0f;
        for(int i = 0; i  < nClientes; i++)
            if(clientes[i] instanceof ClienteMovil){
                ClienteMovil c = (ClienteMovil)clientes[i];
                c.setPrecioMinuto(c.getPrecioMinuto()*descuento);
            }
	}


	public int getN() {
		return nClientes;
	}


	public int nClienteMovil() {
		int numCli=0;
		for (int i=0; i<nClientes;i++)
			if(clientes[i] instanceof ClienteMovil)
				numCli++;
		return numCli;
	}
 	
	@Override
	public String toString() {
		 String texto = "";
	        
	        for(int i = 0; i < nClientes; i++)
	            texto += clientes[i]+"\n";
	        
	        return texto;
	    }

 	
	@Override
	 public Object clone(){
        Empresa obj=null;
        try{
            obj= (Empresa)super.clone();
            obj.clientes = clientes.clone();
            for(int i = 0; i < nClientes; i++)
                obj.clientes[i] = (Cliente)clientes[i].clone();
        }catch(CloneNotSupportedException ex){
            
        }
        return (Object)obj;
    }

}
