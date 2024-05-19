# DogFood

## Apresentação
O presente projeto foi originado no contexto das atividades da disciplina de graduação EA075 - Introdução ao Projeto de Sistemas Embarcados, oferecida no primeiro semestre de 2024, na Unicamp, sob supervisão da Profa. Dra. Paula Dornhofer Paro Costa, do Departamento de Engenharia de Computação e Automação (DCA) da Faculdade de Engenharia Elétrica e de Computação (FEEC).

 |Nome  | RA | Curso|
 |--|--|--|
 | Fernando H. Velmae Nicchio  | 197003  | Eng. de Computação|
 | Rafael Cristian Nascimento  | 223622  | Eng. Elétrica|
 | Victor Potença Macchini | 225205  | Eng.  de Computação |


## Descrição do Projeto
Muitas vezes, pessoas que têm animais de estimação se encontram em uma situação onde precisam se ausentar de sua residência por alguns dias; nessas situações, a preocupação com a alimentação do pet é uma dor inevitável. O projeto é pensado para resolver esse problema,  garantindo a alimentação do animal de estimação de forma automática, regulada, segura e livre de desperdícios - evitando a dor de cabeça do dono com a gestão da ração.

Existem hoje alguns dispositivos até mesmo caseiros que tentam solucionar esse problema, porém, não lidam tão bem com situações adversas: a não-presença do pet em casa, o horário de refeição restrito, a quantidade de porções servidas e o desperdício da comidinha - > fatores que podem comprometer a saúde do animal.

O nosso sistema garante que o animal será servido a porção ideal de sua necessidade, quando lhe for necessária, seguindo pré-programação do usuário. O animal será servido apenas se estiver perto do dispositivo e for chamado para isso - o que garante a adestração do pet e o não desperdício de ração. A quantidade de ração não comida pelo pet é também armazenada, após sua refeição, para prevenir a infestação de insetos.

Dispositivos com propostas semelhantes estão em torno de R$300,00 no mercado hoje. Acreditamos que os diferenciais do produto permitem a entrada do mesmo nessa faixa de preço inicial.



## Descrição Funcional e Descrição Estrutural do Sistema
<img src="\dogfood_diagr.png">

### Funcionalidades
- configurar porções (em gramas) por refeição
- configurar horários de refeição
- configurar horários de recolhimento de restos de ração
- liberar ração em horário configurado
- detectar presença do pet por tag na coleira
- detectar a quantidade de ração restante e aviso
- identificar quantidade de ração liberada
- microfone para gravação de voz
- reprodução de áudio


### Configurabilidade
- quantidade de ração a ser liberada
- voz gravada para reprodução
- horário de liberação da refeição
- horário de recolhimento de restos de ração
- intervalo de chamada do pet quando em horário de refeição


### Eventos
O sistema deve tratar sobre os seguintes eventos/inputs:
1. Janela de horário de refeição (periódico)
2. Horário de fim do dia (periódico)
3. Aproximação do pet (não-periódico)
4. Baixo peso de comida no reservatório (não periódico)
5. Variação do peso de comida no reservatório (não periódico)
6. Horário/tempo de recolhimento de restos de ração (periódico)


### Tratamento de Eventos
- Indicar SE baixa quantidade de comida restante - EVENTO 4
- Reproduzir áudio de chamada do pet em horário específico, dependendo da configuração do usuário, repetição a cada X minutos segundo configurado - EVENTO 1
- Liberar ração SE em horário de refeição E pet está próximo E enquanto a quantidade total de porções não for liberada - EVENTO 1, EVENTO 3 e EVENTO 5
- Liberar comida pelo menos 1 vez ao dia - sistema de segurança para caso evento principal não funcionar - EVENTO 2 e EVENTO 5
- Recolher a ração restante no pote SE passado tempo de recolhimento de restos de ração - EVENTO 6


## Referências
https://www.google.com/search?sca_esv=7b4f5aad248322ac&sca_upv=1&rlz=1C1GCEB_enBR1053BR1053&q=alimentador+de+pet+automatico&tbm=isch&source=lnms&prmd=isvnbmtz&sa=X&ved=2ahUKEwiAr_nVmZqFAxUZppUCHSt9C3cQ0pQJegQIGBAB&biw=1280&bih=559&dpr=3
https://www.lucidchart.com/pages/pt/exemplos/diagrama-de-blocos-online
