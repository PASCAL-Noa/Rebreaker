uniform sampler2D screen_texture;
uniform vec2 direction; // (1,0) pour horizontal, (0,1) pour vertical

void main() {
    vec2 texCoords = gl_TexCoord[0].xy;
    vec4 sum = vec4(0.0);
    float offsets[9] = float[](-4.0, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, 4.0);
    float weights[9] = float[](0.05, 0.09, 0.12, 0.15, 0.18, 0.15, 0.12, 0.09, 0.05);

    for (int i = 0; i < 9; ++i) {
        sum += texture2D(screen_texture, texCoords + offsets[i] * direction / vec2(textureSize(screen_texture, 0))) * weights[i];
    }
    gl_FragColor = sum;
}