# Trabajo-Integrador
Trabajo Integrador: Sistema de Riego Automático
Información del Proyecto


Alumno: Facundo Gabriel Araujo 

Profesor/es: Ing. Gustavo Viard / Ing. Damián Corbalán 


Curso: 2°12 

Modelo de sistema a realizar:
Sistema de Riego Automático, en base a humedad en la tierra.
El proyecto que decidí realizar es un sistema de riego automático que trabaja en sitios o zonas donde el agua dulce existe en bajas proporciones, actúa cuando recibe bajas medidas de humedad en la tierra donde se halla o vaya a haber una planta/árbol/vegetal. Inspirado en el sistema de goteo que ocupan en Israel debido a la baja cantidad de agua dulce que hay en dicho país.
El esquema que plantearía para realizar dicho proyecto es, un circuito cerrado donde existen estados, que cumplan cierto ciclo, el planteado seria:

1° Primer estado, Reposo/Espera, el sistema ocupa un espacio de tiempo para que no este midiendo y ejecutando todo el rato.

2° Segundo estado, Medición, El sistema opera bajo un receptor de humedad el cual detectara y se le crearan condiciones en las que dependiendo un nivel de humedad se activara el riego, caso contrario volverá al estado de Reposo.

3° Tercer estado, Riego, El sistema al detectar un nivel de humedad bajo activara algún mecanismo físico para que durante cierto tiempo riegue la tierra. Una vez finalizado volverá al estado de reposo.

4° Cuarto estado, Mensaje Alarma, el sistema activara una alarma (led rojo) cuando luego del riego la humedad de la tierra se mantenga igual, en resumidas es cuando no halla agua en el regador, luego de este estado se devolverá al estado de espera.
