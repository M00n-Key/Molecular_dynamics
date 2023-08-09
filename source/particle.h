
#pragma once

#include "LinAlgebraLib/vector.h"
#include <cmath>


struct Particle
{
    static float particle_size;
    static float potential_depth;

    float mass;
    Vector3 position;
    Vector3 velocity;
    Vector3 prev_position;
};

float Particle::particle_size = 1;
float Particle::potential_depth = 1;

void move(Particle& particle, float delta_time, Vector3 force)
{
    Vector3 next_position = 2 * particle.position - particle.prev_position + (1 / particle.mass) * force;
    particle.prev_position = particle.position;
    particle.position = next_position;
}

float lennard_johnson_potential(Vector3& source, Vector3& target)
{
    float distance = (source - target).magnitude();

    float potential = Particle::particle_size / distance;

    return 4 * Particle::potential_depth * (powf(potential, 12) - powf(potential, 6));
}

Vector3* calculate_forces(unsigned int num, Particle* particles)
{
    Vector3* forces = new Vector3[num];
    for (unsigned int i = 0; i < num; i++)
    {
        forces[i] = Vector3(0.f, 0.f, 0.f);
        for (unsigned int j = 0; j < num; j++)
        {
            if (i != j)
            {
                float cur_potential = lennard_johnson_potential(particles[i].position, particles[j].position);
                float prev_potential = lennard_johnson_potential(particles[i].prev_position, particles[j].prev_position);

                Vector3 cur_distance = particles[i].position - particles[j].position;
                Vector3 prev_distance = particles[i].prev_position - particles[j].position;
                forces[i] += -(cur_potential - prev_potential) / (cur_distance - prev_distance).magnitude() * (particles[i].position - particles[j].position).normalize();
            }
        }
    }

    return forces;
}

void move_particles(unsigned int num, Particle* particles, float delta_time)
{
    Vector3* forces = calculate_forces(num, particles);
    for (unsigned int i = 0; i < num; i++)
    {
        move(particles[i], delta_time, forces[i]);
    }
}
