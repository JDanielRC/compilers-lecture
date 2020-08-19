file_object = open("log", "r")
if (file_object.mode == "r"):
	contents = file_object.readlines()
	funciones = []
	funcionLocalizacion = []
	instrucciones = []
	instruccionesRepetidas = []
	for x in contents:
		lineAux = x.split()
		if (len(lineAux) != 0):
			if (len(lineAux[0]) == 16):
				funcion = lineAux[1][1:len(lineAux[1])-2]
				funciones.append(funcion)
				funcionLocalizacion.append(lineAux[0])
			elif (len(lineAux[0]) == 5):
				for y in lineAux:
					
					if (len(y) > 2 or (len(y) == 2 and y == 'je')):
						if (y != lineAux[0]):
							instruccionesRepetidas.append(y)
							if (y not in instrucciones):
								instrucciones.append(y)
								break
							break


	class Instruccion:
		def __init__(self, name):
			self.name = name
			self.repeticiones = 0
		def addOne(self):
			self.repeticiones += 1
		
	instruccionesObjects = []
	for x in range(len(instrucciones)):
		valor = Instruccion((instrucciones[x]))
		instruccionesObjects.append(valor)

	for x in range(len(instruccionesRepetidas)):
		for y in range(len(instruccionesObjects)):
			if (instruccionesRepetidas[x] == instruccionesObjects[y].name):
				instruccionesObjects[y].addOne()
	

	#formatting

	print("You have ",len(instrucciones)," instructions in this object file:")
	for x in instruccionesObjects:
		print("", x.name, " : Executed ", x.repeticiones, " times")
	
	print("You have ", len(funciones)," functions:")
	for i in range(len(funciones)):
		print(funciones[i]," : Located at ",funcionLocalizacion[i]," addr")




		