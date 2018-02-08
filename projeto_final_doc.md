# Jogo Gênius  
### Projeto Final da Disciplina de Sistemas Reativos  
###### UERJ | IME - Instituto de Matemática e Estatística | Departamento de Informática e Ciência da Computação  
###### *Rio de Janeiro, Março de 2018*  

**Autor:** Bruno Costa Criscuolo | 201320712211  
**Professor:** Francisco Santana  

---

### Introdução  
Genius foi um jogo que tornou-se muito popular durante a década de 1980 e buscava estimular a memorização, através de cores e sons. De maneira geral o jogo consiste em botões coloridos, iluminados por leds de 4 cores distintas que emitem sons harmônicos ao serem pressionados e acendem em uma sequência aleatória, a qual o jogador deve memorizar e repetir. A cada jogada uma cor é sorteada e iluminada e seu respectivo som é emitido somando-se a sequência já executada anteriormente, de forma que se reproduza uma cadeia cumulativa de cores e sons. No instante em que a nova cor/som é sorteada(o), o jogador deve pressionar o botão correspondente para garantir a repetição exata de todas as entradas anteriores e consequentemente da nova entrada. Caso a cadeia seja interrompida por uma entrada não correspondente, isso é, um som/cor distinto da sequência estabelecida aleatoriamente pelo dispositivo, o jogo é instantaneamente finalizado e um nova sequência será sorteada ao
reiniciar. Como toda sequência é gerada de maneira aleatória, a probabilidade de que uma cadeia se repita é extremamente baixa e é esse efeito que garante o estímulo a memorização.  
  
### Objetivo  
O principal objetivo desse projeto é aplicar, na prática, os conceitos sobre sistemas reativos e conhecimentos adquiridos em sala de aula. Além disso, o estudo prático visa construir um protótipo do dispositivo Genius através do uso de componentes eletrônicos, fundamentado na prática de desenvolvimento de aplicações reativas destinadas a placa de Arduino, usando linguagem de programação própria.  

### Material Utilizado  
Para montagem do protótipo foram utilizados os componentes eletrônicos e materiais listados abaixo:  

* 4 LEDs sendo cada um com seguintes cores: vermelho, azul, amarelo e verde;
* 8 Resistores de 220 ohm;
* 4 Botões do tipo push-button
* 1 Buzzer;
* 1 Protoboard (placa de prototipação);
* 1 Placa de Arduino UNO;
* 1 Cabo USB compatível com Arduino UNO;
* Fios jumper macho-macho;

> [Esquema Conceitual do Circuito](https://drive.google.com/file/d/1pIjAPfi0ZtfShF7HkoTYcRo8zP9BNWSO/view?usp=sharing)  
> [Modelo Físico para Montagem](https://drive.google.com/file/d/1H8VBNg8mXC7F4RSL2zne4AFh_F6tHTe3/view?usp=sharing)  

### Explorando o Código-fonte  
#### 1. Como Funciona o Programa?  
o Programa descreve uma sequência incremental e aleatória de acendimento dos LEDs e o jogador deve segí-la utilizando os botões correspondentes:  
* As luzes permanecem acesas dizendo que o jogo está pronto.
* O jogador deve apertar qualquer botão para iniciar o sorteio do primeiro LED.
* O programa aguarda até que o botão correspondente seja apertado:  é a vez do participante fazer sua jogada.
* Após realização da jogada, o programa comparará o botão apertado com o LED sorteado. Em caso de erro será emitido um som de “desaprovação”. Caso contrário, o programa incrementará mais uma jogada à sequência e um novo LED será aceso randomicamente. Esse processo se repete até que ocorra um erro na entrada do usuário.

