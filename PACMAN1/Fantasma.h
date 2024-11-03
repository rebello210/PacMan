#include <SFML/Graphics.hpp>
#include <cmath>
#include <string>

using namespace sf;
using namespace std;

class Fantasma {
private:
    Sprite sprite;                // Sprite do fantasma para renderização
    Texture texture;              // Textura do fantasma
    float speed;                  // Velocidade de movimento do fantasma
    Vector2f posicaoInicial;      // Posição inicial de nascimento dos fantasmas
    const float raioPerseguicao;  // Raio de perseguição em pixels

public:
    // Construtor
    Fantasma(float initialX, float initialY, float initialSpeed, const string& textureFile, float raio = 256.0f)
        : posicaoInicial(initialX, initialY), speed(initialSpeed), raioPerseguicao(raio) {
        carregarTextura(textureFile);
        sprite.setPosition(initialX, initialY);
    }

    // Função para carregar a textura e inicializar o sprite
    bool carregarTextura(const string& textureFile) {
        if (!texture.loadFromFile(textureFile)) {
            return false;
        }
        sprite.setTexture(texture);
        return true;
    }

    // Atualizar posição baseado na posição do Pac-Man
    void atualizar(float deltaTime, const Vector2f& posicaoPacMan) {
        Vector2f posicaoAtual = sprite.getPosition();
        Vector2f direcao(0.0f, 0.0f);

        // Calcular a distância entre o fantasma e o Pac-Man
        float distancia = sqrt(pow(posicaoPacMan.x - posicaoAtual.x, 2) + pow(posicaoPacMan.y - posicaoAtual.y, 2));

        // Persegue o Pac-Man apenas se ele estiver dentro do raio de perseguição
        if (distancia <= raioPerseguicao) {
            // Calcular direção normalizada em direção ao Pac-Man
            direcao.x = posicaoPacMan.x - posicaoAtual.x;
            direcao.y = posicaoPacMan.y - posicaoAtual.y;
            float magnitude = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
            direcao /= magnitude; // Normalizar o vetor

            // Mover o fantasma em direção ao Pac-Man
            sprite.move(direcao * speed * deltaTime);
        }
    }

    // Renderizar o fantasma
    void renderizar(RenderWindow& window) {
        window.draw(sprite);
    }

    // Resetar posição para a posição inicial
    void resetarPosicao() {
        sprite.setPosition(posicaoInicial);
    }

    // Função para obter posição atual do fantasma
    Vector2f getPosition() const {
        return sprite.getPosition();
    }
};
