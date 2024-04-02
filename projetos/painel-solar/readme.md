# `Painéis Solares de Inclinação Adaptável`
# `Adaptive Slope Solar Panels`

## Apresentação

O presente projeto foi originado no contexto das atividades da disciplina de graduação *EA075 - Introdução ao Projeto de Sistemas Embarcados*, 
oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

> Incluir nome RA e foco de especialização de cada membro do grupo. Os projetos devem ser desenvolvidos em duplas.
> |Nome  | RA | Curso|
> |--|--|--|
> | Mateus Alves Silva | 239856 | Eng. Elétrica |
> | Nathália Kaori Gondo | 239903 | Eng. Elétrica |


## Descrição do Projeto
> Descrição do objetivo principal do projeto, incluindo contexto gerador, motivação.
> Escreva essa seção imaginando que está tentando convencer alguém a investir financeiramente no seu projeto.
> Qual problema vocês pretendem solucionar?
> Quem são os potenciais usuários?
> É possível estabelecer um valor econômico associado?

Com o aumento da demanda por energias limpas e renováveis, como a solar, em residências e indústrias, a necessidade de maximizar a captação de energia solar tornou-se fundamental. No entanto, os sistemas de painéis solares fixos muitas vezes não conseguem se adaptar adequadamente às variações na incidência solar ao longo do dia. Para enfrentar esse desafio, propõe-se um sistema embarcado para automatizar o ajuste da inclinação do painel solar, garantindo uma ótima captação de energia solar em todas as horas do dia. Esse ajuste acompanha o movimento do sol, mantendo-o perpendicular com os raios incidentes, maximizando assim a geração de energia.

O sistema funciona através da detecção da intensidade e direção da luz solar por meio de sensores especializados. Esses sensores fornecem dados da intensidade luminosa, permitindo que uma unidade de controle calcule o ângulo ideal de inclinação do painel solar. Com base nesse cálculo, algoritmos de controle ajustam a inclinação do painel solar em tempo real, garantindo que este esteja sempre posicionado de forma ótima para captar a máxima quantidade de energia solar possível.

Além de contribuir para o avanço da tecnologia renovável, esse sistema oferece benefícios econômicos significativos. A eficiência na captação de energia está diretamente ligada ao ângulo de incidência dos raios solares na placa, o que resulta em uma maior rentabilidade dos investimentos em energia solar. Assim, ao maximizar a geração de energia solar de forma eficiente e econômica, o sistema não só reduz os custos operacionais, mas também aumenta a viabilidade e sustentabilidade dos sistemas de energia renovável.


## Descrição Funcional
> A descrição funcional do projeto é a principal entrega do E1 e pode ser realizada neste próprio arquivo Markdown,
> com links para diagramas ou outros arquivos que estejam no próprio repositório.

O sistema opera em tempo real, monitorando com precisão a intensidade da luz solar incidente sobre o painel solar em busca da angulação ideal para maximizar a geração de energia. Isso é alcançado por meio do controle de um servo motor, cuidadosamente ajustado para posicionar os painéis de forma a otimizar sua exposição aos raios solares. O servo motor, conectado aos painéis através de um eixo, oferece ajustes dinâmicos e contínuos, garantindo que eles permaneçam sempre na posição mais vantajosa em relação à incidência solar, idealmente perpendicular aos raios solares.

O monitoramento da incidência solar é centralizado no dispositivo Inversor do sistema, que não só fornece informações em tempo real sobre a geração de energia, mas também atua como o principal ponto de comunicação para o controle do sistema. Além disso, um sensor fotossensível é incorporado como uma camada adicional de segurança e redundância. Esse sensor garante uma confiabilidade ainda maior na medição da intensidade da luz solar, assegurando uma operação robusta e resiliente do sistema mesmo em condições adversas.

Os dados coletados pelo dispositivo Inversor e pelo sensor fotoresistivo são então processados por um microcontrolador, que implementa um algoritmo de controle inteligente. Este algoritmo é projetado para otimizar continuamente a inclinação dos painéis solares, iniciando com uma angulação inicial de referência e, em seguida, realizando varreduras comparativas. O servo motor é ajustado de forma dinâmica com base nas informações recebidas, parando seu movimento quando a eficiência energética máxima é alcançada. Isso é determinado quando uma redução na eficiência é detectada em relação ao valor anterior, indicando que o ângulo ideal foi encontrado.

Em resumo, esse sistema integrado oferece um controle preciso e adaptativo da inclinação dos painéis solares, garantindo uma captação máxima de energia solar ao longo do dia. Ao combinar tecnologia de monitoramento, controle e robustez, o sistema é capaz de operar de forma confiável e eficiente, contribuindo significativamente para a eficiência energética da geração fotovoltaica. Um esquema do sistema pode ser visto na imagem a seguir.

![image](https://github.com/nathaliagondo/ea075-2024.1/assets/165518289/a88782cf-e8c2-4046-9547-955450b393e3)

### Funcionalidades
> Detalhe todas as tarefas que o sistema será capaz de executar
1. Sun Tracking: O sistema irá monitorar a posição solar usando sensores e ajustando o ângulo de inclinação dos painéis solares para garantir a maior exposição aos raios incidentes.
2. Interface com o usuário: Uma interface que permita o usuário configurar, ajustar o sistema além de apresentar os dados de produção de energia além de informações operacionais do dispositivo.
3. Maximização da Energia produzida: Algoritmo de controle que garanta a máxima geração energética com base na adaptação da angulação do painel solar. Os dados serão processados por meio da tensão e corrente recebidas pelos painéis.
4. Comunicação Wireless: O sistema deverá possuir comunicação sem fio para enviar informações do sistema e receber dados de controle e configuração de um aplicativo para smartphone.
5. Gerenciamento de energia: o sistema será alimentado com a energia solar gerada pelo próprio painel que alimentará uma bateria (usada como backup). A bateria funcionará como um suporte para estabilização da tensão fornecida ao dispositivo. O gerenciamento de energia é essencial para otimizar o consumo de energia e prolongar o tempo de funcionamento do dispositivo.
6. Identificação de erro no sistema ou condição extrema: Verificar esforço extra que o motor é submetido


### Configurabilidade
> Detalhe, se houver, todas as possíveis configurações do circuito e todos os pontos de alteração da configuração.

### Eventos
> Quais eventos o sistema deve tratar?
> Se aplicável, classifique os eventos que são periódicos (procure especificar a periodicidade) e os que são não-periódicos
> (qual o tempo mínimo entre dois eventos sucessivos)?
- Eventos periódicos:
1. Período útil de geração de energia (diário, a cada 24 horas): o período do dia durante o qual o sistema está ativo para captar energia solar e gerar eletricidade. Começando ao nascer do sol e terminando ao pôr do sol, é o intervalo em que a intensidade da luz solar é suficientemente alta para uma produção eficaz de energia.
2. Mudança da posição do sol (diário, a cada poucos minutos - constante): ao longo do dia, a posição do sol no céu se desloca gradualmente devido à rotação da Terra. Essa mudança afeta a quantidade de luz solar que atinge os painéis solares. O sistema deve ajustar a inclinação dos painéis para maximizar a absorção de energia solar.
3. Mudança nas estações do ano (sazonal, a cada três meses, com mudanças graduais entre uma estação e outra): as estações do ano afetam a intensidade e a duração da luz solar incidente devido à inclinação do eixo da Terra. O sistema deve ajustar sua operação e estratégias de captação de energia para otimizar o aproveitamento da luz solar em cada estação.
- Eventos não-periódicos:
4. Condições adversas (variável, depende da frequência e duração das condições): momentos em que as condições climáticas, como nebulosidade, reduzem a intensidade da luz solar disponível para captação. Isso pode resultar em uma diminuição temporária na produção de energia.
5. Condições extremas (variável, depende da frequência e gravidade das condições): eventos climáticos severos, como tempestades e ventanias, que representam riscos para o sistema solar. Nessas situações, medidas de segurança devem ser ativadas para proteger os componentes.
6. Manutenção das placas solares ou dos componentes do sistema (variável, depende do cronograma de manutenção de cada componente): eventos planejados para garantir o bom funcionamento e a longevidade do sistema. Isso inclui inspeções regulares, limpeza de painéis solares para melhor obtenção dos dados e substituição de peças desgastadas.
7. Bateria fraca (variável, condicionada pelo padrão de consumo do sistema): indica que a carga da bateria de armazenamento de energia atingiu um nível baixo. Isso pode ocorrer devido a um consumo excessivo de energia ou a uma incapacidade de recarga adequada das placas solares.
8. Interação do usuário (variável de acordo com a necessidade do usuário): dedicado quando o usuário interage com o sistema, como ajustar configurações, monitorar o desempenho ou receber notificações sobre o status do sistema.
9. Falhas no sistema (imprevisível, dependendo da natureza e gravidade da falha): ocorrência de problemas ou mau funcionamento no sistema solar que exigem intervenção técnica. Isso pode incluir falhas de hardware, erros de software ou interrupções na geração de energia.

### Tratamento de Eventos
> Qual comportamento o sistema deve ter para tratar corretamente cada evento?
1. Período útil de geração de energia: 
    - Iniciar automaticamente os painéis solares e o sistema de geração de energia ao nascer do sol e ajustar a inclinação dos painéis solares ao longo do dia para acompanhar o movimento do sol, de modo a maximizar a captação de energia.
    - Desativar os painéis solares e o sistema de geração de energia ao pôr do sol para evitar a consumo de energia desnecessária durante a noite.
2. Mudança da posição do sol:
    - Ajustar a inclinação dos painéis solares em tempo real para garantir que estejam sempre alinhados da maneira mais eficiente possível com a incidência de luz solar.
    - Monitorar continuamente a produção de energia e consumo, realizando ajustes automáticos na inclinação ao longo do dia para acompanhar o movimento do sol e otimizar a eficiência energética.
3. Mudança nas estações do ano:
    - Com base na data e posição do sol, ajustar as configurações de inclinação dos painéis solares e os algoritmos de captação de energia para otimizar o desempenho de acordo com as condições específicas de cada estação.
    - Adaptar as estratégias de armazenamento e uso de energia para melhor atender às necessidades sazonais de energia.
4. Condições adversas:
    - Monitorar a ocorrência de mudanças na obtenção dos dados, para ajusar as operações dos painéiso solares, lidando com a redução na intensidade da luz solar.
    - Implementar medidas de economia de energia para preservar a energia disponível durante períodos de baixa produção.
5. Condições extremas:
    - Identificar ventanias e tempestades por meio de variações bruscas no torque do servomotor. 
    - Ativar um modo de segurança que retraia os painéis solares e desative temporariamente a geração de energia para proteger os componentes do sistema contra danos.
    - Emitir alertas aos usuários sobre as condições climáticas extremas.
6. Manutenção das placas solares ou dos componentes do sistema:
    - Agendar automaticamente tarefas de manutenção com base em intervalos predefinidos ou em condições específicas do sistema.
    - Desativar temporariamente os painéis solares e o sistema de geração de energia durante a manutenção para garantir a segurança durante as limpezas e substituições de componentes desgastados.
7. Bateria fraca:
    - Monitorar continuamente o nível de carga da bateria de armazenamento de energia.
    - Reduzir automaticamente o consumo de energia ou ajustar as operações dos painéis solares para preservar a energia restante da bateria.
    - Emitir alertas aos usuários sobre a bateria fraca.
8. Interação do usuário:
    - Prioridade em relação aos demais eventos, respondendo rapidamente às solicitações.
    - Interface intuitiva do sistema-usuário
9. Falhas no sistema:
    - Tentar realizar correções automáticas, quando possível, e diagnósticos das falhas.
    - Se não for possível corrigi-lo, desativar o sistema e emitir alertas ao usuário indicando as falhas.


## Descrição Estrutural do Sistema
> Junto com a descrição do comportamento do sistema, deve-se especificar, em nível de bloco ou sistema, a estrutura necessária 
> para captar os eventos do mundo externo, para alojar e processar o programa de tratamento de eventos, e para atuar sobre o mundo externo.
>
> Para essa descrição recomenda-se a criação de diagramas de blocos.
> Nesse diagrama, devem ser destacados os blocos funcionais que compõem o sistema, incluindo uma síntese das funcionalidades de cada bloco.
> Além disso, deve-se esclarecer também o relacionamento entre estes blocos, incluindo os principais sinais de comunicação entre
> os blocos de forma a assegurar a execução de todas as tarefas que o sistema deve realizar.
> 
> Você sabia? Ferramentas como o `draw.io` permitem integração com o Github.
> ![Inicializar](https://github.com/nathaliagondo/ea075-2024.1/assets/165518289/fc771e96-53b4-4542-a22a-ef8bc89a5591)


## Referências
> Seção obrigatória. Inclua aqui referências utilizadas no projeto.
