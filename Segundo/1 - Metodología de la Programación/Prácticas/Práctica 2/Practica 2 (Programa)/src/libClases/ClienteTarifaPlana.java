package libClases;

public class ClienteTarifaPlana extends Cliente {

	private static int 		minutosTP = 300;
	private static float 	precioTP = 20;
	private static float 	precioExcesoMinutos = 0.15f;
	
	private float 	minutosHablados;
	private String 	nacionalidad;
	
	public ClienteTarifaPlana(String NIF, String nom, Fecha fNac, Fecha fAlta, float minHab, String Nacion) {
		super(NIF, nom, fNac, fAlta);
		this.minutosHablados=minHab;
		this.nacionalidad=Nacion;
	}// Constructor
	
	public ClienteTarifaPlana(String NIF, String nom, Fecha fNac, float minHab, String Nacion) {
		super(NIF, nom, fNac);
		this.minutosHablados=minHab;
		this.nacionalidad=Nacion;
	}
	
	public ClienteTarifaPlana(ClienteTarifaPlana c) {
		super(c);
		this.minutosHablados = c.minutosHablados;
		this.nacionalidad = c.nacionalidad;
	}
	
	@Override
	public float factura() {
		//return this.precioTP + (this.minutosHablados>this.minutosTP?(this.minutosHablados-this.minutosTP)*precioExcesoMinutos:0);
		return precioTP + (minutosHablados>minutosTP?(minutosHablados-minutosTP)*precioExcesoMinutos:0);
	}
	
	public void setLimiteMinutos(int LimMin) {
		minutosTP=LimMin;
	}
	
	public static void setTarifaPlana(int m, float p) {
		minutosTP=m;
		precioTP=p;
	}
	
	public void setMinutosHablados(int min) {
		minutosHablados=min;
	}
	
	public float getMinutos() {
		return minutosHablados;
	}
	
	public String getNacionalidad() {
		return nacionalidad;
	}

	public void setNacionalidad(String nac) {
		this.nacionalidad=nac;
	}
	
	public static float getTarifa() {
		return precioTP;
	}
	
	public static int getLimite() {
		return minutosTP;
	}
	
	@Override
	public String toString() {
		return super.toString()+" "+nacionalidad+"[ "+minutosTP+" por "+precioTP+"] " + minutosHablados + ": "+factura();
	}
	
	@Override
	public Object clone() {
		return new ClienteTarifaPlana(getNif(), getNombre(), getFechaNac(), getFechaAlta(), getMinutos(), getNacionalidad());
	}
	
	@Override
	public boolean equals(Object o) {
		return o instanceof ClienteTarifaPlana && getNif().equals(((Cliente)o).getNif());
	}
}
