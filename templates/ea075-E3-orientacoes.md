# 2023.1 EA075 - Projeto - E3 - Entrega Final

## Instruções Gerais

Nesta última entrega:
 * É suposto que você continue editando o projeto no fork criado anteriormente (opcionalmente, sugere-se que antes de iniciar a edição, você sincronize seu fork com a última versão do repositório principal).
 * Faça o commit dos arquivos associados a esta entrega, conforme descrito nas seções a seguir.
 * Quando tudo estiver pronto para entrega, crie nova uma tag de release no repositório identificada como `2023.2_EA075_E3`.
 * Até a data de submissão estabelecida, crie um pull request para este repositório.

## Componentes
Na raiz do seu projeto, seu grupo deverá submeter um arquivo chamado `components.md`

Este arquivo deverá ter uma lista dos componentes escolhidos para seu projeto justificando a escolha de cada um, com um link para o datasheet do componente (sempre que possível).

## Pastas de Projeto

Na entrega final do seu projeto, você deverá criar e popular a seguinte estrutura de diretórios conforme orientações.
```
project
│   README.md
│   components.md   
│
└───3d_models     // Esta pasta é *OPCIONAL*. Arquivo PDF com a impressão da visão 3D do PCB
└───datasheets    // Esta pasta é *OPCIONAL*. Arquivos PDF dos datasheets dos componentes 
                  // (note que o link dos datasheets é obrigatório no arquivo components.md)
└───gerber        // Esta pasta é *OBRIGATÓRIA*. Arquivos finais de produção da PCB.
└───pdf           // Esta pasta é *OBRIGATÓRIA*. Incluir aqui arquivos PDF importados do esquemático, 
                  // layout da placa e outros arquivos relevantes do projeto.
└───images        // Esta pasta é *OBRIGATÓRIA*. Incluir aqui arquivos SVG (preferencialmente) da placa, 
                  // do modelo 3D e outras imagens relevantes do projeto.
└───src_zip       // Esta pasta é *OBRIGATÓRIA*. Incluir aqui arquivo ZIP com reunião de arquivos do projeto 
                  // que possibilite abertura do mesmo em software EDA. Esta pasta deve conter um arquivo *.md 
                  // dando instruções de abertura do projeto. 

```

## Orientações para edição do arquivo README.md do projeto

Para a entrega E3, o README.md do repositório deve ser atualizado [segundo o modelo disponibilizado neste link](https://github.com/teaching-FEEC/ea075-2024.1/blob/main/templates/ea075-E3-template.md). Toda e qualquer alteração do projeto em relação à entrega E2 deve ser explicitada e justificada.

> Tudo o que aparecer neste modo de citação se refere a algo que deve ser substituído pelo indicado (retire o sinal de >). 
