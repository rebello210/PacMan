#include <SFML/Graphics.hpp>

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
    Vector2f direction;      // Direção atual do Pac-Man

public:
    // Construtor
    PacMan(float initialX, float initialY, float initialSpeed, const string& textureFile);

    // Função para carregar a textura e inicializar o sprite
    bool carregarTextura(const string& textureFile);

    // Atualizar posição baseado na direção
    void atualizar(float deltaTime);

    // Renderizar o Pac-Man
    void renderizar(RenderWindow& window);

    // Função para obter posição
    Vector2f getPosition() const;

    // Função para definir posição (útil para resetar ou reposicionar)
    void setPosition(float x, float y);
};
