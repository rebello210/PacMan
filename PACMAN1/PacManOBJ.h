#include <SFML/Graphics.hpp>

enum class Direcao {
    CIMA,
    BAIXO,
    ESQUERDA,
    DIREITA
};
class PacMan {
private:
    Sprite sprite;           // Sprite do Pac-Man para renderiza��o
    Texture texture;         // Textura do Pac-Man
    float speed;             // Velocidade de movimento do Pac-Man
    Vector2f direction;      // Dire��o atual do Pac-Man

public:
    // Construtor
    PacMan(float initialX, float initialY, float initialSpeed, const string& textureFile);

    // Fun��o para carregar a textura e inicializar o sprite
    bool carregarTextura(const string& textureFile);

    // Atualizar posi��o baseado na dire��o
    void atualizar(float deltaTime);

    // Renderizar o Pac-Man
    void renderizar(RenderWindow& window);

    // Fun��o para obter posi��o
    Vector2f getPosition() const;

    // Fun��o para definir posi��o (�til para resetar ou reposicionar)
    void setPosition(float x, float y);
};
