#version 410

mat4 buildRotateX(float rad);
mat4 buildRotateY(float rad);
mat4 buildRotateZ(float rad);

void main(void)
{ 
  vec4 positionVec;
  if (gl_VertexID == 0) positionVec = vec4(0.25, -0.25, 0.0, 1.0);
  else if (gl_VertexID == 1) positionVec = vec4(-0.25, -0.25, 0.0, 1.0);
  else positionVec = vec4(0.25, 0.25, 0.0, 1.0);

  mat4 xRotation = buildRotateX(10.0);
  mat4 yRotation = buildRotateX(10.0);
  mat4 zRotation = buildRotateX(10.0);

  gl_Position = xRotation * yRotation * zRotation * positionVec;
}

mat4 buildRotateX(float rad)
{
  mat4 xRotation = mat4(1.0, 0.0, 0.0, 0.0,
                        0.0, cos(rad), -sin(rad), 0.0,
                        0.0, sin(rad), cos(rad), 0.0,
                        0.0, 0.0, 0.0, 1.0);

  return xRotation;
}

mat4 buildRotateY(float rad)
{
  mat4 yRotation = mat4(cos(rad), 0.0, sin(rad), 0.0,
                        0.0, 1.0, 0.0, 0.0,
                        -sin(rad), 0.0, cos(rad), 0.0,
                        0.0, 0.0, 0.0, 1.0);

  return yRotation;
}

mat4 buildRotateZ(float rad)
{
  mat4 zRotation = mat4(cos(rad), -sin(rad), 0.0, 0.0,
                        sin(rad), cos(rad), 0.0, 0.0,
                        0.0, 0.0, 1.0, 0.0,
                        0.0, 0.0, 0.0, 1.0);

  return zRotation;
}
