    #include <iostream>
    #include <vector>
    #include <string>
    #include <random>
    #include <numeric>

    std::vector<std::string> ligne1 = { " ", " ", " " };
    std::vector<std::string> ligne2 = { " ", " ", " " };
    std::vector<std::string> ligne3 = { " ", " ", " " };
    std::vector<int> ligne1int = { 0, 0, 0 };
    std::vector<int> ligne2int = { 0, 0, 0 };
    std::vector<int> ligne3int = { 0, 0, 0 };
    bool victoire = false;

    void check_victoire(std::vector<int> ligne1int, std::vector<int> ligne2int, std::vector<int> ligne3int, std::string gagnant){
        
            if ((accumulate(ligne1int.begin(), ligne1int.end(), 0)) == 3){
                std::cout << "Victoire de " << gagnant << std::endl;
                victoire = true;
                abort();
            }
            if ((accumulate(ligne2int.begin(), ligne2int.end(), 0)) == 3){
                std::cout << "Victoire de " << gagnant << std::endl;
                victoire = true;
                abort();
            }
            if ((accumulate(ligne3int.begin(), ligne3int.end(), 0)) == 3){
                std::cout << "Victoire de " << gagnant << std::endl;
                victoire = true;
                abort();
            }
            if ((ligne1int[0] + ligne2int[0] + ligne3int[0] == 3)){
                std::cout << "Victoire de " << gagnant << std::endl;
                victoire = true;
                abort();
            }
            if ((ligne1int[1] + ligne2int[1] + ligne3int[1] == 3)){
                std::cout << "Victoire de " << gagnant << std::endl;
                victoire = true;
                abort();
            }
            if ((ligne1int[2] + ligne2int[2] + ligne3int[2] == 3)){
                std::cout << "Victoire de " << gagnant << std::endl;
                victoire = true;
                abort();
            }
            if ((ligne1int[0] + ligne2int[1] + ligne3int[2] == 3)){
                std::cout << "Victoire de " << gagnant << std::endl;
                victoire = true;
                abort();
            }
            if ((ligne1int[2] + ligne2int[1] + ligne3int[0] == 3)){
                std::cout << "Victoire de " << gagnant << std::endl;
                victoire = true;
                abort();
            }
            else {
                victoire = false;
            }
    }
    int ia (int entree_joueur, int numero_coup, std::vector<int> ligne1int, std::vector<int> ligne2int, std::vector<int> ligne3int)
    {
        int a_retourner = rand() % 9 + 1;
        while ((ligne1int[a_retourner - 1] != 0) or (ligne2int[a_retourner - 4] != 0) or (ligne3int[a_retourner - 7] != 0)){
            int a_retourner = rand() % 9 + 1;
        }
        return a_retourner;

    }
    void dessiner_grille(std::vector<std::string> ligne1, std::vector<std::string> ligne2, std::vector<std::string> ligne3)
    {
        std::cout << ligne1[0] << " | " << ligne1[1] << " | " << ligne1[2] << std::endl;
        std::cout << ligne2[0] << " | " << ligne2[1] << " | " << ligne2[2] << std::endl;
        std::cout << ligne3[0] << " | " << ligne3[1] << " | " << ligne3[2] << std::endl;
        std::cout << "\n" << "\n";
    }
    void definir_vecteurs(int entree_joueur, int entree_ordi)
    {

        switch (entree_joueur) {

            case 1 :
            case 2 : 
            case 3 :
            {
                ligne1[entree_joueur - 1] = "X";
                ligne1int[entree_joueur - 1] = 1;
                break;
            }
            case 4:
            case 5:
            case 6:
            {
                ligne2[entree_joueur - 4] = "X";
                ligne2int[entree_joueur - 4] = 1;
                break;
            }
            case 7:
            case 8:
            case 9:
            {
                ligne3[entree_joueur - 7] = "X";
                ligne3int[entree_joueur - 7] = 1;
                break;
            }
        }
        switch (entree_ordi) {

            case 1 :
            case 2 : 
            case 3 :
            {
                ligne1[entree_ordi - 1] = "O";
                ligne1int[entree_joueur - 1] = 1;
                break;
            }
            case 4:
            case 5:
            case 6:
            {
                ligne2[entree_ordi - 4] = "O";
                ligne2int[entree_joueur - 4] = 1;
                break;
            }
            case 7:
            case 8:
            case 9:
            {
                ligne3[entree_ordi - 7] = "O";
                ligne3int[entree_joueur - 7] = 1;
                break;
            }
        }


    }

    int main(){
        int entree_joueur;
        std::cout << "\n" << "\n";
        std::cout << "----- Morpion -----" << std::endl;
        std::cout << "\n" << "\n";

        dessiner_grille(ligne1, ligne2, ligne3);
        int numero_coup = 0;
        while (!victoire){

            std::cout << "\n" << "A toi de jouer : " << std::endl;
            std::cin >> entree_joueur;
            std::cout << "\n";
            numero_coup++;
            definir_vecteurs(entree_joueur, 0);
            check_victoire(ligne1int, ligne2int, ligne3int, "Joueur");
            definir_vecteurs(0, ia(entree_joueur, numero_coup, ligne1int, ligne2int, ligne3int));
            check_victoire(ligne1int, ligne2int, ligne3int, "Ordinateur");
            numero_coup++;
            dessiner_grille(ligne1, ligne2, ligne3);

        }

    }
