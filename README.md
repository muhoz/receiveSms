# receiveSms
Hi, this is a simple code to control gsm module connected to an arduino for example. The objective there is to succeed to connect the two modules and have a successful communication.

Sometimes connect the gsm modules to the Arduino can be painfull for your head, i have been working on a multiple of modules(SIM808,SIM900,SIM900A,A6...) and find the good way to connect it
was a great challenge with the ressources on the internet. I have tried to do a simple tutorial on how to connect them (Arduino and gsm module) and the rest of tests(sending messages, recieving messages)
will be more detailed on other projects.

The connection between the Arduino and the most gsm modules are as follow:

Arduino                                             -------------       GSM module
Digital pin(choose whatever you want) Ex: #3            ----                TX
Digital pin(choose whatever you want) Ex: #2            ----                RX
GND                                                     ----                GND

In my experiences, the ground is necessary but some modules don't need it. You can try and see by yourself.
An image on the folder presents an example of connection between an arduino nano and an SIM808 module.

Hope this, will help you.
