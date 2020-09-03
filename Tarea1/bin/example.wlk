/** First Wollok example */
object equipo {
	
	var jugadores = 22
	var contagiados = 0
	
	method nuevoContagio (cantidadNuevosContagiados) {
		contagiados = contagiados + cantidadNuevosContagiados
	}

	method cuantosNoContagiados(){
		return jugadores - contagiados
	}
	
	method cuantosContagiados (){
		return contagiados	
	}
}
