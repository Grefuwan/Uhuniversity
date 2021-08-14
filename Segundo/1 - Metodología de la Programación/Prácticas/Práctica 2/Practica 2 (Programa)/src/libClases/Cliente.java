package libClases;

public class Cliente {
	
	private static int contador = 1;
	private static final Fecha defaultFecha = new Fecha(1, 1, 2018);
	
	private final String nif;	//dni del cliente (letra incluida) (No puede cambiar)
	private final int codCliente;	//codigo unico (y fijo) generado por la aplicacion
	private String nombre;	//Nombre completo del cliente (SI se puede modificar)
	private final Fecha fechaNac;
	private final Fecha fechaAlta;
	
	public Cliente (String NIF, String nom, Fecha fNac, Fecha fAlta) {
		this.nif = NIF;
		this.nombre=nom;
		this.fechaNac=(Fecha)fNac.clone();
		this.fechaAlta = (Fecha)fAlta.clone();
		this.codCliente=contador;
		contador = contador + 1;
	} //constructor
	
	public Cliente (String NIF, String nom, Fecha fNac) {
		this.nif = NIF;
		this.nombre=nom;
		this.fechaNac=(Fecha)fNac.clone();
		this.fechaAlta = defaultFecha;
		this.codCliente=contador;
		contador = contador + 1;
	} //constructor

	public Cliente(Cliente c) {
		this(c.nif, c.nombre, c.fechaNac, c.fechaAlta);
	} //constructor copia

	public String toString() {//Devuelve una cadena con la informacion del cliente
		return nif+" "+fechaNac+": "+nombre+" ("+codCliente+" - "+fechaAlta+")";
	}
	
	public final Fecha getFechaAlta() {
		return (Fecha)fechaAlta.clone();		//Hay que poner (Fecha) porque el metodo clone() hace casting
	}
	
	public final Fecha getFechaNac() {
		return (Fecha)fechaNac.clone();
	}
	
	public final void setFechaAlta(Fecha setFeAl) {
		this.fechaAlta.setFecha(setFeAl.getDia(),setFeAl.getMes(),setFeAl.getAnio());
	}
		
	public final void setNombreAtributo(String nome) {
		this.nombre=nome;
	}
	
	public final String getNif(){
		return nif;
	}
	
	public final int getCodCliente() {
		return codCliente;
	}
	
	public final String getNombre() {
		return nombre;
	}
	
	public float factura() {
		throw new UnsupportedOperationException("No se puede facturar un cliente sin tipo.");
	}
	
	public void ver() {
		System.out.println(this);
	}
	
	public boolean equals(Object o) {
		return o.getClass() == Cliente.class && nif.equals(((Cliente)o).nif);
	}
	
	public Object clone() {
		return new Cliente(this);
	}
	
	public final static Fecha getDefaultFecha() {
		return (Fecha)defaultFecha.clone();
	}
	
	public final static void setDefaultFecha(Fecha f) {
		defaultFecha.setFecha(f.getDia(), f.getMes(), f.getAnio());
	}
}
