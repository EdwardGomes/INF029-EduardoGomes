//Converte o numerobase e numerobusca em strings
    char numBase[11];
    sprintf(numBase, "%d", numerobase);
    char numBuscaStr[11];
    sprintf(numBuscaStr, "%d", numerobusca);

    //Percorre a string numBase
    for (int i = 0; i < strlen(numBase); i++) {
        bool match = true;
        //Percorre a string numBuscaStr
      for (int j = 0; j < strlen(numBuscaStr); j++) {
         //Verifica se os dígitos correspondentes são iguais  
        if (numBase[i+j] != numBuscaStr[j]) {
         //Se houver diferença, o match é falso e o loop interno é quebrado     
            match = false;
            break;
            }
        }
        //Se todos os dígitos correspondentes forem iguais, incrementa a quantidade de ocorrências
        if (match) {
            qtdOcorrencias++;
        }
    }