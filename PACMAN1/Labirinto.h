#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;
using namespace sf;

class LabirintoPacMan {
private:
    vector<vector<bool>> matriz; // Matriz para representar o labirinto
    RectangleShape parede;                 // Shape para desenhar as paredes
    const float tamanhoCelula = 32.0f;     // Tamanho da célula do labirinto

public:
    LabirintoPacMan(int largura, int altura) {
        matriz.resize(altura, vector<bool>(largura, false)); // Inicializa todas as células como livres
        parede.setSize(Vector2f(tamanhoCelula, tamanhoCelula));
        parede.setFillColor(Color::Blue);
    }

    void desenhar(RenderWindow& window) {
        for (int y = 0; y < matriz.size(); ++y) {
            for (int x = 0; x < matriz[y].size(); ++x) {
                if (matriz[y][x]) {
                    parede.setPosition(x * tamanhoCelula, y * tamanhoCelula);
                    window.draw(parede);
                }
            }
        }
    }

    bool haParede(int x, int y) const {
        if (x >= 0 && x < matriz[0].size() && y >= 0 && y < matriz.size()) {
            return matriz[y][x];
        }
        return true; // Considera como parede se estiver fora dos limites
    }

    void definirParede(int x, int y) {
        if (x >= 0 && x < matriz[0].size() && y >= 0 && y < matriz.size()) {
            matriz[y][x] = true;
        }
    }

    void removerParede(int x, int y) {
        if (x >= 0 && x < matriz[0].size() && y >= 0 && y < matriz.size()) {
            matriz[y][x] = false;
        }
    }
};
