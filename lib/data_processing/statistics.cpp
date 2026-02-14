// File: lib/data_processing/statistics.cpp
// Description: Implementations for non-template statistics helpers
// INTERNAL LIBRARIES (Use "")
#include "statistics.h"

// This is the source file for the statistics functions.
// The template functions must be declared and defined in the header.

QuaternionRotation quaternionMultiply(QuaternionRotation a, QuaternionRotation b)
{
    QuaternionRotation temp;
    temp.w = (a.w) * (b.w) - (a.i) * (b.i) - (a.j) * (b.j) - (a.k) * (b.k);
    temp.i = (a.w) * (b.i) + (a.i) * (b.w) + (a.j) * (b.k) - (a.k) * (b.j);
    temp.j = (a.w) * (b.j) - (a.i) * (b.k) + (a.j) * (b.w) + (a.k) * (b.i);
    temp.k = (a.w) * (b.k) + (a.i) * (b.j) - (a.j) * (b.i) + (a.k) * (b.w);
    return temp;
}

QuaternionRotation quaternionInverse(QuaternionRotation q)
{
    QuaternionRotation temp;
    double normSquared = quaternionNormSquared(q);
    temp = quaternionConjugate(q);
    temp.w /= normSquared;
    temp.i /= normSquared;
    temp.j /= normSquared;
    temp.k /= normSquared;
    return temp;
}

QuaternionRotation quaternionConjugate(QuaternionRotation q)
{
    QuaternionRotation temp;
    temp.w = q.w;
    temp.i = -q.i;
    temp.j = -q.j;
    temp.k = -q.k;
    return temp;
}

double quaternionNormSquared(QuaternionRotation q)
{
    return (square<double>(q.w) + square<double>(q.i) + square<double>(q.j) + square<double>(q.k));
}

QuaternionRotation normQuaternion(QuaternionRotation rotation)
{
    QuaternionRotation tempQuaternion;
    double magnitude = sqrt(quaternionNormSquared(rotation));
    tempQuaternion.w = rotation.w / magnitude;
    tempQuaternion.i = rotation.i / magnitude;
    tempQuaternion.j = rotation.j / magnitude;
    tempQuaternion.k = rotation.k / magnitude;
    return tempQuaternion;
}

QuaternionRotation swingTwistDecompositionPartialT(Position axis, QuaternionRotation rotation)
{
    QuaternionRotation projection;
    projection.w = rotation.w;

    double componentScalar;
    componentScalar = (axis.x * rotation.i) + (axis.y * rotation.j) + (axis.z * rotation.k);
    componentScalar /= (square<double>(axis.x) + square<double>(axis.y) + square<double>(axis.z));
    projection.i = axis.x * componentScalar;
    projection.j = axis.y * componentScalar;
    projection.k = axis.z * componentScalar;

    return projection;
}

QuaternionRotation swingTwistDecompositionPartialS(QuaternionRotation twist, QuaternionRotation rotation)
{
    QuaternionRotation inverseTwist;
    inverseTwist = quaternionInverse(rotation);
    return quaternionMultiply(rotation, inverseTwist);
}

Position rotateVecQuaternion(Position vec, QuaternionRotation rotation)
{
    QuaternionRotation tempQuaternion;
    tempQuaternion.w = 0;
    tempQuaternion.i = vec.x;
    tempQuaternion.j = vec.y;
    tempQuaternion.k = vec.z;

    tempQuaternion = quaternionMultiply(tempQuaternion, quaternionConjugate(rotation));
    tempQuaternion = quaternionMultiply(rotation, tempQuaternion);

    vec.x = tempQuaternion.i;
    vec.y = tempQuaternion.j;
    vec.z = tempQuaternion.k;

    return vec;
}