#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

enum class Direcao {
    CIMA,
    BAIXO,
    ESQUERDA,
    DIREITA
};

class PacMan {
private:
    Sprite sprite;           // Sprite do Pac-Man para renderização
    Texture texture;         // Textura do Pac-Man
    float speed;             // Velocidade de movimento do Pac-Man
    Direcao direction;       // Direção atual do Pac-Man

public:
    PacMan(float initialX, float initialY, float initialSpeed, const string& textureFile)
        : speed(initialSpeed), direction(Direcao::DIREITA) {
        carregarTextura(textureFile);
        sprite.setPosition(initialX, initialY);
    }

    bool carregarTextura(const string& textureFile) {
        if (!texture.loadFromFile(textureFile)) {
            return false;
        }
        sprite.setTexture(texture);
        return true;
    }

    void atualizar(float deltaTime) {
        Vector2f movimento(0.0f, 0.0f);
        switch (direction) {
        case Direcao::CIMA:    movimento.y = -speed * deltaTime; break;
        case Direcao::BAIXO:   movimento.y = speed * deltaTime; break;
        case Direcao::ESQUERDA: movimento.x = -speed * deltaTime; break;
        case Direcao::DIREITA: movimento.x = speed * deltaTime; break;
        }
        sprite.move(movimento);
    }

    void renderizar(RenderWindow& window) {
        window.draw(sprite);
    }

    Vector2f getPosition() const {
        return sprite.getPosition();
    }

    void setPosition(float x, float y) {
        sprite.setPosition(x, y);
    }

    void setDirecao(Direcao novaDirecao) {
        direction = novaDirecao;
    }
};
