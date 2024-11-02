#include <SFML/Graphics.hpp>
#include <vector>

const int LARGURA = 1000;
const int ALTURA = 800;
const int TAMANHO_CELULA = 20;
using namespace sf;

std::vector<std::vector<int>> mapa = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


void desenhaMapa(sf::RenderWindow& janela, sf::RectangleShape& parede, sf::CircleShape& pelota) {
    for (size_t y = 0; y < mapa.size(); ++y) {
        for (size_t x = 0; x < mapa[y].size(); ++x) {
            if (mapa[y][x] == 1) {
                parede.setPosition(x * TAMANHO_CELULA, y * TAMANHO_CELULA);
                janela.draw(parede);
            }
            else if (mapa[y][x] == 0) {
                pelota.setPosition(x * TAMANHO_CELULA + TAMANHO_CELULA / 4, y * TAMANHO_CELULA + TAMANHO_CELULA / 4);
                janela.draw(pelota);
            }
        }
    }
}

bool podeMover(int x, int y) {
    int celulaX = x / TAMANHO_CELULA;
    int celulaY = y / TAMANHO_CELULA;
    return mapa[celulaY][celulaX] != 1;
}

int main() {
    RenderWindow janela(VideoMode(LARGURA, ALTURA), "Pac-Man");
    RectangleShape parede(Vector2f(TAMANHO_CELULA, TAMANHO_CELULA));
    parede.setFillColor(Color::Blue);

    CircleShape pelota(TAMANHO_CELULA / 6);
    pelota.setFillColor(Color::White);

    CircleShape pacman(TAMANHO_CELULA / 2);
    pacman.setFillColor(Color::Yellow);
    pacman.setOrigin(TAMANHO_CELULA / 2, TAMANHO_CELULA / 2);
    pacman.setPosition(2 * TAMANHO_CELULA, 2 * TAMANHO_CELULA);

    Vector2f velocidade(0, 0);
    float velocidadePacman = 0.2f;

    while (janela.isOpen()) {
        Event evento;
        while (janela.pollEvent(evento)) {
            if (evento.type == Event::Closed)
                janela.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            velocidade = Vector2f(0, -velocidadePacman);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Down)) {
            velocidade = Vector2f(0, velocidadePacman);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Left)) {
            velocidade = Vector2f(-velocidadePacman, 0);
        }
        else if (Keyboard::isKeyPressed(Keyboard::Right)) {
            velocidade = Vector2f(velocidadePacman, 0);
        }
        else {
            velocidade = Vector2f(0, 0);
        }

        Vector2f novaPosicao = pacman.getPosition() + velocidade;
        if (podeMover(novaPosicao.x, novaPosicao.y)) {
            pacman.setPosition(novaPosicao);
        }

        int pacX = pacman.getPosition().x / TAMANHO_CELULA;
        int pacY = pacman.getPosition().y / TAMANHO_CELULA;
        if (mapa[pacY][pacX] == 0) {
            mapa[pacY][pacX] = -1;  // Marca a pelota como comida
        }

        janela.clear();
        desenhaMapa(janela, parede, pelota);
        janela.draw(pacman);
        janela.display();
    }

    return 0;
}