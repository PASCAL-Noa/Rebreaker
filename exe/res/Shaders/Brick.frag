uniform vec4 color;
uniform sampler2D crack_texture;
uniform float crack_amount;

float sdBox( in vec2 p, in vec2 b )
{
    vec2 d = abs(p)-b;
    return length(max(d,0.0)) + min(max(d.x,d.y),0.0);
}

void main()
{
    vec2 uv = gl_TexCoord[0].xy;
    uv = (uv - 0.5) * 2.0;

    float d = sdBox(uv, vec2(crack_amount, crack_amount));
    d = 1.0 - step(0.01, d);

    vec4 tex = texture(crack_texture, gl_TexCoord[0].xy);

    if (d == 0.0)
    {
        gl_FragColor = color;
    } else {
        gl_FragColor = tex * color;
    }
}