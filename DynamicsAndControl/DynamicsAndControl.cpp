#include "stdafx.h"

#include "Rendering/Primitives/Physics.h"
#include "Rendering/Scene/Scene.h"
#include "Game/Game.h"
#include "Simulations/CartSpring.h"
#include <thread>

static void Reshape(int width, int height)
{
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

Rendering::Scene gScene;

static void Draw(void)
{
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT), -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor4f(1, 1, 1, 0.5);
    Rendering::Renderer renderer;
    renderer.RenderScene(gScene);
    glutSwapBuffers();

    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void Idle() {
    glutPostRedisplay();
}

void RunGame() {
    Game::Game game(1.f/60);
    std::unique_ptr<Game::Simulation> sim = std::make_unique<Simulations::CartSpring>(&gScene);
    game.ResetSimulation(sim);
    game.Run();
}

int main(int argc, char **argv)
{
    GLenum type;

    glutInit(&argc, argv);

    type = GLUT_RGB | GLUT_ACCUM | GLUT_DOUBLE;
    glutInitDisplayMode(type);
    glutInitWindowSize(1000, 600);
    glutCreateWindow("Sims");

    glClearColor(.1, .1, .1, 0.5);

    std::thread th(RunGame);

    glutReshapeFunc(Reshape);
    glutIdleFunc(Idle);
    glutDisplayFunc(Draw);
    glutMainLoop();

    th.join();

    return 0;
}

