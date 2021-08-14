package libClases;

import java.util.Scanner;

public final class Fecha implements Cloneable, Proceso {
	private int dia;
	private int mes;
	private int anio;
	
	public void setFecha(int d, int m, int a) {
		int dmax, diaMes[]= {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		anio=a;
		if (m<1)
			m=1;
		else if (m>12)
			m=12;
		
		dmax=diaMes[m-1];
		if(m==2 && bisiesto())
			dmax++;
		if (d>dmax)
			d=dmax;
		else if (d<1)
			d=1;
		
		dia=d;
		mes=m;
	}
	
	public Fecha(int dia, int mes, int anio) {
		setFecha(dia, mes, anio);
	}
	
	public Fecha(Fecha f) {
		dia=f.dia;
		mes=f.mes;
		anio=f.anio;
	}

	public int getDia() {return dia;}
	public int getMes() {return mes;}
	public int getAnio() {return anio;}
	
	@Override
	public String toString() {
		String s="";
		if (dia<10)
			s=s+0;
		s=s+dia+"/";
		if(mes<10)
			s=s+0;
		s=s+mes+"/"+anio;
		return s;
		//Lo anterior se puede sustituir por lo siguiente:
		//return String.format("%02d/%02d/%02d", dia, mes, anio);
	}
	
	
	public boolean bisiesto() {
		boolean b=false;
		if(anio%4==0) {
			b=true;
			if(anio%100==0 && anio%400!=0)
				b=false;
		}
		return b;
	}
	
	
    public static Fecha pedirFecha(){
        Scanner s = new Scanner(System.in);
        Fecha f = null;
        boolean valida;
        
        do{
            System.out.print("Introduce una fecha (dd/mm/aaaa): ");
            String[] datos = s.nextLine().split("/");
            if(datos.length != 3){
                valida = false;
            }else{
                int fDia = Integer.parseInt(datos[0]), fMes = Integer.parseInt(datos[1]), fAnio = Integer.parseInt(datos[2]);
                int maxDias[] = {0,31,(fAnio%400 == 0 || (fAnio%4 == 0 && fAnio%100 != 0))?29:28,31,30,31,30,31,31,30,31,30,31};
                valida = fMes >= 1 && fMes <= 12 && fDia >= 1 && fDia <= maxDias[fMes];
                if(valida)
                    f = new Fecha(fDia, fMes, fAnio);
            }
            if(!valida)
                System.out.println("Fecha no valida");
        }while(!valida);
        return f;
    }
	
	
	static public boolean mayor(Fecha f1, Fecha f2) {
		if (f1.anio*10000+f1.mes*100+f1.dia > f2.anio*10000+f2.mes*100+f2.dia)
			return true;
		else
			return false;
	}
	
	@Override
	public Object clone() {
		Object obj=null;
		try {
			obj=super.clone();
		}
		catch(CloneNotSupportedException ex) {
			System.out.println("No se puede duplicar");
		}
		return obj;
	}
	
	@Override
	public boolean equals (Object obj) {
		if (this==obj)return true;
		if (obj==null)return false;
		if (getClass() != obj.getClass())
			return false;
		Fecha c= (Fecha) obj;
		return (dia==c.dia && mes==c.mes && anio==c.anio);
	}
	
	@Override
	public void ver() {
		System.out.println(this/*.toString*/);
	}

	public static void main(String[] args) {
		Fecha f1 = new Fecha(29,2,2001), f2 = new Fecha(f1), f3 = new Fecha(29,2,2004);
		final Fecha f4=new Fecha(05,12,2003); //es constante la referencia f4
		System.out.println("Fechas: " + f1.toString() + ", " + f2 + ", " + f3 + ", " + f4);
		f1=new Fecha(31,12,2016); //31/12/2016
		f4.setFecha(28, 2, 2008); //pero no es constante el objeto al que apunta
		System.out.println(f1 +" "+ f2.toString() +" " + f3 + " "+ f4 + " "+ f1);
		f1=new Fecha(f4.getDia()-10, f4.getMes(), f4.getAnio()-7); //f1=18/02/2001
		f3=Fecha.pedirFecha(); // pide una fecha por teclado
		if (f3.bisiesto() && Fecha.mayor(f2,f1))
		System.out.println("El " + f3.getAnio() + " fue bisiesto, " + f1 + ", " + f3);
		System.out.print("Fin\n");
		}

	public Fecha diaSig() {
        Fecha f = (Fecha)clone();
        
        f.dia++;

        int maxDias[] = {0,31,bisiesto()?29:28,31,30,31,30,31,31,30,31,30,31};

        //El incremento de dias afecta al mes y al año
        if(f.dia > maxDias[f.mes]){
            f.dia -= maxDias[f.mes];
            f.mes++;
            if(f.mes > 12){
                f.mes = 1;
                f.anio++;
            }
        }
        
        return f;
	}
}






















