import socket
import time

import Pyro4

numero = 1
numCuca = 2

uri = "PYRO:Robot_3@192.168.1.10:9090"
o = Pyro4.Proxy(uri)

print("Robot " + str(numero) + " conectando...")
o.client_connected(numero, socket.gethostname())
print("Robot " + str(numero) + " conectado")

persecucion = o.cuca_perseguida(numero, numCuca)

time.sleep(3)

if persecucion:
    print("Persecucion valida")
elif not persecucion:
    print("Persecucion NO valida")

time.sleep(11)
o.libera_cuca(numero, numCuca)
# Devolver true si puede perseguirla y comenzar a perseguirla
# Devolver false si no puede, y buscar otra
