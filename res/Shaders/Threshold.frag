uniform sampler2D screen_texture;

void main() {
    vec4 color = texture2D(screen_texture, gl_TexCoord[0].xy);
    if (dot(color.rgb, vec3(0.299, 0.587, 0.114)) > 0.4) 
    {
        gl_FragColor = color;
    } else {
        gl_FragColor = vec4(0.0);
    }
}