import Pyro4
import platform
import subprocess


@Pyro4.expose
@Pyro4.callback
class RobotCliente:
    # False = Libre -- True = Ocupada
    numeroCucas = 7
    lista_cucas = [0] * numeroCucas

    cambios = 0

    print("Estado inicial de las cucarachas: ")
    for i in range(numeroCucas):
        print("\t\tCucaracha " + str(i) + ": {}".format(lista_cucas[i]))
    print("\n")

    def client_connected (self, numRobot, direccion):
        # print("\nCliente conectado: {}".format(uri))
        try:
            print("\nSoy el robot " + str(numRobot) + " conectado desde " + str(direccion))
        except:
            print("Error de conexion con el robot " + str(numRobot) + "---------------------------- !!!")

    def cuca_perseguida(self, numRobot, numCuca):
        print("Soy el robot " + str(numRobot) + " y estoy persiguiendo la cuca " + str(numCuca))
        if self.lista_cucas[numCuca] is 0:
            self.lista_cucas[numCuca] = numRobot
            self.cambios += 1
            # Comenzar a perseguir
            persecucionValida = True
        else:
            print("El robot " + str(numRobot) + " no puede perseguir la cucaracha " + str(numCuca) + "\n")
            persecucionValida = False

        print("Cucarachas tras " + str(self.cambios) + " cambios:")
        for i in range(self.numeroCucas):
            print("\t\tCucaracha " + str(i) + ": {}".format(self.lista_cucas[i]))

        return persecucionValida

    def libera_cuca(self, numRobot, numCuca):
        print("Soy el robot " + str(numRobot) + " y libero la cucaracha " + str(numCuca))
        self.lista_cucas[numCuca] = 0


# Registro los objetos Pyro4 que se vayan conectando
#   Creo una instancia del robot conectado
robot1 = RobotCliente()
robot2 = RobotCliente()
robot3 = RobotCliente()

#   Creo un daemon Pyro4
if platform.system() == 'Windows':
    local = subprocess.getoutput("""for /f "tokens=2 delims=[]" %a in ('ping -n 1 -4 "%computername%"') do @echo %a""")
else:
    local = subprocess.getoutput("ifconfig | grep 'inet ' | grep -Fv 127.0.0.1 | awk '{print $2}'")
print("Direccion IP Local: " + str(local))

daemon = Pyro4.Daemon(host=local, port=9090)

#   Registro los objetos en el daemon
uri1 = daemon.register(robot1, "Robot_1")
uri2 = daemon.register(robot2, "Robot_2")
uri3 = daemon.register(robot3, "Robot_3")
print("URI 1: " + str(uri1))
print("URI 2: " + str(uri2))
print("URI 3: " + str(uri3))

#   Inicio el servidor
print("Lanzando servidor\n\n")
daemon.requestLoop()
print("Servidor lanzado")
