# `Controlador de MOSFETs`
# `MOSFETs Controller`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).


 |Nome  | RA | Curso|
 |--|--|--|
| Gabriel Tavares Coluccini Francisco  | 239640  | Eng. Elétrica|
| João Pedro Souza Pascon  | 239733  | Eng. Elétrica|


## Arquivos Importantes

projetos/controlador_senoidal/componentes.md

## Descrição do Projeto

No atual contexto macroeconômico global, marcado por cortes nas taxas de juros, tanto do FED quanto do BC, e a busca por oportunidades de investimento mais rentáveis, surge um cenário de oportunidades significativas para os empreendedores e investidores. É esperado que, nos próximos anos, o contexto econômico se recupere dos danos causados pela pandemia do COVID 19 e que o custo do capital diminua, impulsionando novos projetos de engenharia, novas oportunidades de negócios e novos setores da economia.

É dentro desse cenário promissor que visamos o projeto de um Gate Driver, cuja função principal é comandar motores e tratar energia elétrica. Observe a versatilidade do dispositivo, dada a importância do uso de motores e energia elétrica. No contexto de novas oportunidades, podemos destacar os emergentes mercados de transição energética e eletrificação veicular, além das antigas indústrias já bem consolidadas que utilizam esses equipamentos para controle de motores.

Em relação ao setor de automação, temos em mente os desafios de mercado a serem enfrentados, visto que este setor é dominado por gigantes multinacionais (como Siemens; RockWell; ABB e a brasileira WEG) com produtos muito bem estabelecidos e alto poder de investimentos.

No entanto, apesar dos desafios, destacamos as oportunidades apresentadas pela transição energética e pela eletrificação veicular. Setores diversos, desde usinas sucroalcooleiras (Raízen e São Martinho), empresas de celulose como Klabin e Suzano, além de novas áreas, como novos parques eólicos (muito proeminentes nas regiões sul e nordeste); parques solares; novas usinas de etanol de milho e as empresas geradoras, transmissoras e distribuidoras de energia (CPFL e NeoEnergia) estão buscando soluções eficazes para o controle de motores e sistemas de energia.

Um catalizador importante para a tese são as novas tecnologias de MOSFETs utilizando os materiais WBG – como SiC e GaN – que  emergem como um ponto de inflexão no mercado, oferecendo vantagens substanciais, ainda que em estágio de desenvolvimento de pesquisa, uma vez que essa tecnologia ainda não está bem consolidada e está em constante avanço. O aprofundamento em nuances destes materiais alongaria o corpo deste texto para o projeto específico desta disciplina, mas, é preciso ter consciência da importância destes materiais para a viabilização econômica do dispositivo.



Concebido para proporcionar uma curva de aprendizado gradual e familiarização com o sistema, nosso modelo rudimentar de Gate Driver é especialmente projetado para aplicações em half-bridges com carga indutiva para onda senoidal. Embora reconheçamos que o desenvolvimento de dispositivos de última geração requer um investimento considerável em recursos e expertise, nosso produto oferece uma oportunidade valiosa para iniciar uma jornada no campo da eletrônica de potência.

Em suma, nosso Gate Driver de MOSFET não apenas representa uma solução eficaz para os desafios do controle de potência, mas também serve como uma porta de entrada para a compreensão e exploração das complexidades deste campo dinâmico e crucial para o futuro energético global.

 ## Descrição Funcional
 
Embora seja fato que diversos gate drivers comerciais já existentes e bem estabelecidos comercialmente propõem inúmeras funções como: operações do MOSFET em regiões de triodo; adaptabilidade de Vgs; e, nos mais avançados, controle ativo. O projeto proposto não visa chegar em tal ponto de adaptabilidade e escalabilidade, mas sim, permitir um modelo base para criar o início de uma curva de aprendizado e, se possível, futuras melhorias.

Dessa forma, como funcionalidade do projeto, propomos a implementação de um algoritmo em um DSP, que realiza a leitura de potenciômetros, a fim controlar sua frequência de operação e amplitude da onda senoidal resultante de uma fonte de corrente contínua.

Também, é muito importante, em dispositivos de tal forma, monitorar alguns parâmetros de qualidade e falhas e feedback do que acontece. Usaremos alguns leds para isso e espicificaremos essas falhas à medida que o projeto caminha.

Duas configurações de leitrua devem ser feitas: 
- Ler o potênciometro de frequência
- Ler o potênciometro de amplitude
- Detectar se algum dos potenciômetros desconectar
- Detectar sobrecorrentes
- Monitoramento da temperatura

 ### Tratamento de Eventos

Não esperamos que o dispositivo seja inteligente o suficiente para tratar de falhas, mas que pelo menos passe um feedback de qual falha ocorreu.

- LED vermelho - Temperatura alta
- LED verde - Potênciometros desconectados
- LED Azul - Problemas com a corrente

## Descrição Estrutural do Sistema:

(TRABALHAR EM UM DIAGRAMA SOBRE O ALGORITMO EM C) REFERENCIAS DO RASHID

Explicando o circuito: Temos uma fonte de corrente contúnua, que será estabilizada por dois capacitores. O circuito em verde, mostra a lógica do algoritmo SPWM em hardware. Depois, temos um push-pull. Após isso, temos um filtro.

![image](https://github.com/jppascon/ea075-2024.1/assets/163413469/6c2f74a3-67c1-4651-83fb-c9299a4416da)

### Simulações

Antes de especificar o que devemos comprar para o projeto, foi proposto uma primeira bateria de simulações. Do próprio circuito mostrado acima, juntamente com o algoritmo de controle SPWM. Nessa primeira simulação, os valores foram ajustados por eurística.
Validamos as simulacoes da seguinte maneira, em regime permanente:

![image](https://github.com/jppascon/ea075-2024.1/assets/163413469/31154cb5-75fb-454c-b4cd-275f42ed491e)

Observe que, validando com o que era esperado pelo livro do RASHID, temos uma bom modelo por hora.

![image](https://github.com/jppascon/ea075-2024.1/assets/163413469/62213e9e-1e95-45f3-ba51-8c04969d2dce)

Controlando a amplitude e frequência da onda carrier, nós controlamos a amplitude e a frequência da onda de saída. Pretendemos fazer isso via software e utiizar a região de modulação linear.



## Especificações

### Especificações Estrutruais

Vamos nos interessar bastante em quais seriam as vantagens e desvantagens de cada componente. Dando enfoque nos motivos que acarretaram na escolha final do dispositivo. Para os objetos que serão necessários termos:

- Potenciômetros
- Microcontrolador
- Capacitores
- MOSFETs
- Sensores de Temperatura, Corrente
- LEDs RGB

### Microcontrolador

Nesse caso, temos, juntamente com o MOSFET, o componente mais importante do projeto. Dentre os inúmeros microcontroladores disponíveis, optou-se pelo uso do MKL25Z da freescale. A maior justificativa para essa decisão foi um trade-off entre tempo de desenvolvimento somado a eficiencia contra custos. Com certeza poderíamos ter optado por um arduino que pudesse fornecer e tratar os dados que precisamos, mas, como nossa equipe possui amplo conhecimento no comando do dispositivo MKL25Z, é nítida sua escolha como microcontrolador ideal, visto que no contexto atual de projeto, o tempo de projeto e disponibilidade de componentes (encontramos tal microcontrolador amplamente disponível) são as variáveis de maior importância em qualquer trade-off que devemos fazer.


Em relação aos LEDs, como mostra a imagem abaixo, podemos nos embasar nos LEDs imbutidos na própria placa. Usaremos os pinos PTB18, PTB19, PTD1.
![image](https://github.com/jppascon/ea075-2024.1/assets/163413469/86a1ed5c-e399-4828-b749-14b842f9e5fd)

Em relação aos  pinos a serem utilizados serão: PTE20, PTE21, PTE22, PTE23. Configurados em ADC.
![image](https://github.com/jppascon/ea075-2024.1/assets/163413469/b99420d2-144f-40ab-bdbf-a6a1c7c82111)

![image](https://github.com/jppascon/ea075-2024.1/assets/163413469/d99a68dc-318b-41c5-8954-af230b85a955)


Para o output, devemos utilizar um pino GPIO ou PWM. A decisão ainda está em aberto, para manter conformidade com o código.

### Sensor de Temperatura
  
Para a escolha do sensor de temperatura para o circuito que estamos planejando implementar alguns requisitos prévios precisavam ser contemplados, como a contabilidade com o case do MOSFET a ser utilizado, medição precisa e rápida de temperatura, facilidade na medição, ou seja, não necessidade de circuitos externos para mensurar e, por conseguinte, garantir a complexidade e preço necessários para a implementação no projeto.

Destarte, foram analisadas três opções de sensores: Termistor NTC, Termopar e Termorresistência de Platina (PT100). Assim, optou-se pelo Termistor NTC devido a sua compatibilidade com a case do MOSFET, sua conveniência de montagem através de furos (through-hole), simplicidade, custo relativamente baixo, resposta rápida e adequação para medições de temperatura em dispositivos eletrônicos como MOSFETs.

Ademais, a priorização do sensor supracitado em relação aos outros supramencionados está associada a diversos fatores, visto que o Termopar, por exemplo, apesar de ser robusto e capaz de medir temperaturas extremas, necessita de circuitos de amplificação e compensação de junção fria para assegurar a precisão, além de ser mais complexo e, possivelmente, mais caro que o necessário. A Termorresistência de Platina (PT100), por outro lado, embora ofereça alta precisão e estabilidade a longo prazo, seu custo elevado, necessidade de circuitos de excitação mais complexos e resposta mais lenta, a tornaram menos atraente para esta aplicação específica.

Portanto, o Termistor NTC foi a escolha ideal, proporcionando simplicidade, custo relativamente baixo, resposta rápida e adequação para medições de temperatura em dispositivos eletrônicos como MOSFETs. Dito isso, foi optado pelo Termistor NTC. O modelo escolhido, que ainda pode estar sujeito a mudanças, EPCOS B57560G103F.

### Sensor de Corrente

Para os sensores de corrente, vamos optar por um resistor shunt. Acreditamos que ele apresenta como sendo mais simples que um resistor por campo magnético e mais acessível.

### Capacitores

Em relação aos capacitores, para as demandas do projeto foram escolhidos dois capacitores de 100 uF, devido ao fato de apresentarem uma boa estabilidade de tensão, ou seja, são capazes de suportar flutuações de tensão, garantindo uma alimentação estável para o MOSFET, evitando oscilações e garantindo o funcionamento adequado do dispositivo.

 Além disso, são capazes de realizar a filtragem de ruídos e picos de tensão indesejados que possam ser introduzidos na linha de alimentação .E, também são comumente encontrados, relativamente compactos em tamanho e disponíveis em uma ampla variedade de faixas de tensão. Logo, são adequados para a aplicação e facilmente integrados ao projeto eletrônico. O capacitor escolhido, visando uma tensão de 32V iniciais para testes foi ECW-F2105JB, mas ainda podendo estar sujeito a mudanças.

### Potênciometros

 Para mensurar a tensão e ajustar a frequência no projeto, foi optado pela escolha do potenciômetro Bourns 3296W Series, sua escolha foi motivada por diversos fatores, como precisão e resolução, visto que oferecem uma precisão excepcional, permitindo ajustes finos de tensão e frequência. Sua capacidade de múltiplas voltas oferece uma resolução alta o suficiente para garantir ajustes precisos, ou seja, ideal para aplicações em que a precisão é essencial. Além disso, apresentam alta durabilidade e estabilidade a longo prazo, garantindo que o ajuste realizado permaneça consistente ao longo do tempo, mesmo em ambientes com condições adversas ou sujeitos à vibrações. 
 Por fim, embora potênciometros de alta precisão geralmente tenham um cusco mais elevado, a série Bourns 3296W oferece uma ótima relação de custo-benefício, tornando-o uma escolha econômica para a aplicação desejada, além do fato de serem altamente disponíveis em distribuidores de componentes eletrônicos, facilitando sua aquisição e garantindo a disponibilidade para o projeto. Portanto, é uma escolha sólida ao analisarmos os fatores supracitados.

## Futuras melhorias

Melhoria e desenvolvimento contínuo são características que nós valorizamos e acreditamos para a engeharia de produtos. Dessa forma, gostaríamos de pontuar os próximos passos a serem desenvolvidos a fim de dar forma ao projeto. 
Um circuito de bootstrap é necessário para a implementação desse cirucito, ele é responsápor por viabilizar um referencial  de tensão para o MOSFET superior  do  push-pull, visto que a tensão entre gate e source não tem o referencial no terra
O algoritmo fornecido, é uma ótima base para a configuração do microcontrolador e da lógica. Apesar disso, um controle de frequência é difícil de ser aplicado nesse caso.
O resistor shunt utilizado para medir a corrente, mede apenas a corrente que passa pelo source do MOSFET inferior da meia ponte, e seria interessante, para projetos mais elaborados, aferir a corrente em outros pontos também.
Sobre a parte mecânica, que apesar de extremamente importante, foi quase completamente ignorada nesse projeto. Em futuras melhorias, é preciso dimensionar um dissipadora de calor a uma posição correta para o sensor de temperatura.

## Referencias

RASHID, M. H. (2001) Power Electronics Handbook

J. F. Guerreiro, H. Guillardi and J. A. Pomilio, "Design Procedures and Prototyping of a
Full-Bridge High Frequency Power Inverter," 2019 IEEE 15th Brazilian Power Electronics
Conference and 5th IEEE Southern Power Electronics Conference (COBEP/SPEC), Santos, Brazil,
2019, pp. 1-6, doi: 10.1109/COBEP/SPEC44138.2019.9065318.
keywords: {MOSFET;Logic gates;Capacitors;Gate
drivers;Oscillators;Inverters;Switches;MOSFETs;Power Converter;Inverter;High Switching
Frequency}






