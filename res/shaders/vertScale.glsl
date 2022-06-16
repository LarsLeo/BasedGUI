#version 410

mat4 buildScale(float x, float y, float z);

void main(void)
{ 
  vec4 positionVec;
  if (gl_VertexID == 0) positionVec = vec4(0.25, -0.25, 0.0, 1.0);
  else if (gl_VertexID == 1) positionVec = vec4(-0.25, -0.25, 0.0, 1.0);
  else positionVec = vec4(0.25, 0.25, 0.0, 1.0);

  mat4 scaleMat = buildScale(0.3, 0.3, 0.3);

  gl_Position = scaleMat * positionVec;
}

mat4 buildScale(float x, float y, float z)
{
  mat4 scaleMat = mat4(x, 0.0, 0.0, 0.0,
                        0.0, y, 0.0, 0.0,
                        0.0, 0.0, z, 0.0,
                        0.0, 0.0, 0.0, 1.0);

  return scaleMat;
}
