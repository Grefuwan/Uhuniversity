import customtkinter
from DeteccionCucas_Servidor import ServerCucas
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


def iniciarServidor():
    global hilo, hilo_activo
    if not hilo_activo:
        hilo_activo = True
        hilo = threading.Thread(target=ServerCucas().lanzarServer)
        hilo.start()
        estadoServidor.configure(text="Server encendido", fg_color="green", corner_radius=10)

    else:
        print("ERROR: Servidor ya lanzado")


def cambiarEstadoCuca(numRobot, numCuca):
    if numCuca == 1:
        estadoC1.configure(text="C1 siendo cazada", fg_color="#97dd26")
    elif numCuca == 2:
        estadoC2.configure(text="C2 siendo cazada", fg_color="#97dd26")
    elif numCuca == 3:
        estadoC3.configure(text="C3 siendo cazada", fg_color="#97dd26")
    elif numCuca == 4:
        estadoC4.configure(text="C4 siendo cazada", fg_color="#97dd26")
    elif numCuca == 5:
        estadoC5.configure(text="C5 siendo cazada", fg_color="#97dd26")
    elif numCuca == 6:
        estadoC6.configure(text="C6 siendo cazada", fg_color="#97dd26")
    elif numCuca == 7:
        estadoC7.configure(text="C7 siendo cazada", fg_color="#97dd26")


botonLanzarServer = customtkinter.CTkButton(master=frame, corner_radius=15, text="Lanzar Servidor",
                                            command=iniciarServidor)
estadoServidor = customtkinter.CTkLabel(master=frame, text="Server apagado", fg_color="red", corner_radius=10)
estadoC1 = customtkinter.CTkLabel(master=frame, text="C1 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC2 = customtkinter.CTkLabel(master=frame, text="C2 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC3 = customtkinter.CTkLabel(master=frame, text="C3 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC4 = customtkinter.CTkLabel(master=frame, text="C4 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC5 = customtkinter.CTkLabel(master=frame, text="C5 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC6 = customtkinter.CTkLabel(master=frame, text="C6 Libre", fg_color="#6d0f0f", corner_radius=10)
estadoC7 = customtkinter.CTkLabel(master=frame, text="C7 Libre", fg_color="#6d0f0f", corner_radius=10)

frame.pack(pady=20, padx=40, fill="both", expand=True)
imgC1Label.place(x=10, y=50)
imgC2Label.place(x=10, y=55 + tam)
imgC3Label.place(x=10, y=60 + 2 * tam)
imgC4Label.place(x=10, y=65 + 3 * tam)
imgC5Label.place(x=tam * 7, y=50)
imgC6Label.place(x=tam * 7, y=55 + tam)
imgC7Label.place(x=tam * 7, y=60 + 2 * tam)

botonLanzarServer.place(x=400, y=25)
estadoServidor.place(x=415, y=60)
estadoC1.place(x=135, y=113)
estadoC2.place(x=135, y=232)
estadoC3.place(x=135, y=350)
estadoC4.place(x=135, y=465)
estadoC5.place(x=730, y=113)
estadoC6.place(x=730, y=232)
estadoC7.place(x=730, y=350)

root.mainloop()
