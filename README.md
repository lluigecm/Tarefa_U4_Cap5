﻿# Controle de LEDs com Temporizador One Shot

## Descrição
Com o auxílio do simulador de eletrônica Wokwi, foram utilizados 3 leds (vermelho, amarelo e verde) e um botão, para simular um Temporizador One Shot. Nessa prática foram simulados os seguintes componentes:

1) Microcontrolador Raspberry Pi Pico W.
2) 03 LEDs (vermelho, amarelo e verde).
3) 3 resistores de 330 Ω. 
4) Botão (Pushbutton). 

## Observações
- Caso queira rodar o codigo na placa BitDogLab, interprete o led azul como amarelo.
- Essa branch é da atividade 2, caso queira compilar a atividade 1 alterne para a outra branch disponível.

## Como compilar
Para compilar o programa, utilize um compilador C, e rode o código para geração do arquivo `.uf2` e `.elf`. Segue um exemplo:

![botao compilador](photos_readme/compilador.png)

## Como executar
Após a compilação, execute o simulador Wokwi clicando no arquivo `diagram.json`:

![circuito](photos_readme/circuito.png)

Para testar, só clicar no play e observar o funcionamento do semáforo.

## Requisitos
- Compilador C (gcc ou equivalente).
- Sistema operacional compatível com programas C.
- Extensão Raspberry Pi Pico 
- Wokwi conectado no VS Code
