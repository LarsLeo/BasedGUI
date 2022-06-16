#version 410

mat4 buildTranslate(float x, float y, float z);

void main(void)
{ 
  vec4 positionVec;
  if (gl_VertexID == 0) positionVec = vec4(0.25, -0.25, 0.0, 1.0);
  else if (gl_VertexID == 1) positionVec = vec4(-0.25, -0.25, 0.0, 1.0);
  else positionVec = vec4(0.25, 0.25, 0.0, 1.0);

  mat4 vecTranslation = buildTranslate(0.3, 0.3, 0.3);

  gl_Position = vecTranslation * positionVec;
}

mat4 buildTranslate(float x, float y, float z)
{
  mat4 vecTranslation = mat4(1.0, 0.0, 0.0, 0.0,
                          0.0, 1.0, 0.0, 0.0,
                          0.0, 0.0, 1.0, 0.0,
                          x, y, z, 1.0);

  return vecTranslation;
}
