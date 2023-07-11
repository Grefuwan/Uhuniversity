import Pyro4
import platform
import subprocess
import socket
import customtkinter
from PIL import Image
import threading


pathC1 = r"/media/jgv/HDD/Documentos/Universidad/UHU/Uhuniversity/Cuarto/IAAR/IAAR_PyDeteccionCucas/images/cuca_1 - blue_red.png"
pathC2 = r"/media/jgv/HDD/Documentos/Universidad/UHU/Uhuniversity/Cuarto/IAAR/IAAR_PyDeteccionCucas/images/cuca_2 - grey_yellow.png"
pathC3 = r"/media/jgv/HDD/Documentos/Universidad/UHU/Uhuniversity/Cuarto/IAAR/IAAR_PyDeteccionCucas/images/cuca_3 - blue_green.png"
pathC4 = r"/media/jgv/HDD/Documentos/Universidad/UHU/Uhuniversity/Cuarto/IAAR/IAAR_PyDeteccionCucas/images/cuca_4 - black_red.png"
pathC5 = r"/media/jgv/HDD/Documentos/Universidad/UHU/Uhuniversity/Cuarto/IAAR/IAAR_PyDeteccionCucas/images/cuca_5 - white_green.png"
pathC6 = r"/media/jgv/HDD/Documentos/Universidad/UHU/Uhuniversity/Cuarto/IAAR/IAAR_PyDeteccionCucas/images/cuca_6 - grey_green.png"
pathC7 = r"/media/jgv/HDD/Documentos/Universidad/UHU/Uhuniversity/Cuarto/IAAR/IAAR_PyDeteccionCucas/images/cuca_7 - orange.png"

customtkinter.set_appearance_mode("system")
customtkinter.set_default_color_theme("dark-blue")

root = customtkinter.CTk()
root.geometry("1020x680")
root.title("Servidor de Cucarachas")

tam = 115
imgCuca1 = customtkinter.CTkImage(light_image=Image.open(pathC1), size=(tam, tam))
imgCuca2 = customtkinter.CTkImage(light_image=Image.open(pathC2), size=(tam, tam))
imgCuca3 = customtkinter.CTkImage(light_image=Image.open(pathC3), size=(tam, tam))
imgCuca4 = customtkinter.CTkImage(light_image=Image.open(pathC4), size=(tam, tam))
imgCuca5 = customtkinter.CTkImage(light_image=Image.open(pathC5), size=(tam, tam))
imgCuca6 = customtkinter.CTkImage(light_image=Image.open(pathC6), size=(tam, tam))
imgCuca7 = customtkinter.CTkImage(light_image=Image.open(pathC7), size=(tam, tam))

frame = customtkinter.CTkFrame(master=root)
imgC1Label = customtkinter.CTkLabel(master=frame, image=imgCuca1, text="")
imgC2Label = customtkinter.CTkLabel(master=frame, image=imgCuca2, text="")
imgC3Label = customtkinter.CTkLabel(master=frame, image=imgCuca3, text="")
imgC4Label = customtkinter.CTkLabel(master=frame, image=imgCuca4, text="")
imgC5Label = customtkinter.CTkLabel(master=frame, image=imgCuca5, text="")
imgC6Label = customtkinter.CTkLabel(master=frame, image=imgCuca6, text="")
imgC7Label = customtkinter.CTkLabel(master=frame, image=imgCuca7, text="")

hilo = None
hilo_activo = False

botonLanzarServer = customtkinter.CTkButton(master=frame, corner_radius=15, text="Lanzar Servidor",
                                        command=ServerCucas.lanzarServer)
estadoServidor = customtkinter.CTkLabel(master=frame, text="Server apagado", fg_color="red", corner_radius=10)
estadoC1 = customtkinter.CTkLabel(master=frame, text="C1 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC2 = customtkinter.CTkLabel(master=frame, text="C2 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC3 = customtkinter.CTkLabel(master=frame, text="C3 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC4 = customtkinter.CTkLabel(master=frame, text="C4 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC5 = customtkinter.CTkLabel(master=frame, text="C5 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC6 = customtkinter.CTkLabel(master=frame, text="C6 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC7 = customtkinter.CTkLabel(master=frame, text="C7 Libre", fg_color="#6d0f0f", corner_radius=10)

def iniciarServidor(self):
    if not self.hilo_activo:
        self.hilo_activo = True
        self.hilo = threading.Thread(target=ServerCucas().lanzarServer)
        self.hilo.start()
        self.estadoServidor.configure(text="Server encendido", fg_color="green", corner_radius=10)

    else:
        print("ERROR: Servidor ya lanzado")


@Pyro4.expose
@Pyro4.callback
class Servidor:
    # False = Libre -- True = Ocupada
    numeroCucas = 7
    lista_cucas = [0] * numeroCucas

    cambios = 0

    print("Estado inicial de las cucarachas: ")
    for i in range(numeroCucas):
        print("\t\tCucaracha " + str(i) + ": {}".format(lista_cucas[i]))
    print("\n")

    def client_connected(self, numRobot, direccion):
        # print("\nCliente conectado: {}".format(uri))
        try:
            print("\nSoy el robot " + str(numRobot) + " conectado desde " + str(direccion))
        except:
            print("Error de conexion con el robot " + str(numRobot) + "---------------------------- !!!")

    def cuca_perseguida(self, numRobot, numCuca):
        print("Soy el robot " + str(numRobot) + " y estoy persiguiendo la cuca " + str(numCuca))
        if self.lista_cucas[numCuca] == 0:
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


class ServerCucas:
    def __init__(self):
        self.hilo_activo = False

    def lanzarServer(self):
        if not self.hilo_activo:
            # Registro los objetos Pyro4 que se vayan conectando
            #   Creo una instancia del robot conectado
            robot1 = Servidor()
            robot2 = Servidor()
            robot3 = Servidor()

            #   Creo un daemon Pyro4
            if platform.system() == 'Windows':
                local = subprocess.getoutput(
                    """for /f "tokens=2 delims=[]" %a in ('ping -n 1 -4 "%computername%"') do @echo %a""")
            else:
                hostname = socket.gethostname()
                local = socket.gethostbyname(hostname)
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

    def finalizarServer(self):
        self.hilo_activo = False
