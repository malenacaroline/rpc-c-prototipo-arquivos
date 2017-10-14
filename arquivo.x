struct arquivo{
	int id[7];
	char nome[100];
	char conteudo[1000];
};
program opera_arquivos{
	version opera_arquivos1{
		int criar_arquivo(arquivo) = 1;
		int deletar_arquivo(arquivo) = 2;
		int copiar_arquivo(arquivo) = 3;
		int escrever_arquivo(arquivo) = 4;
		int ler_arquivo(arquivo) = 5;

	} = 100;
}= 9999;
