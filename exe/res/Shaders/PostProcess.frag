uniform sampler2D bloom_texture;
uniform sampler2D screen_texture;

float CURVATURE = 4.2;
float BLUR = .031;
float CA_AMT = 1.007;

void main()
{
	vec2 uv=gl_TexCoord[0].xy;

	//curving
	vec2 crtUV=uv*2.-1.;
	vec2 offset=crtUV.yx/CURVATURE;
	crtUV+=crtUV*offset*offset;
	crtUV=crtUV*.5+.5;

	vec2 edge=smoothstep(0., BLUR, crtUV)*(1.-smoothstep(1.-BLUR, 1., crtUV));

	vec3 color;
	//chromatic abberation
	color.rgb = vec3(
	texture(screen_texture, (crtUV-.5)*CA_AMT+.5).r,
	texture(screen_texture, crtUV).g,
	texture(screen_texture, (crtUV-.5)/CA_AMT+.5).b
	)*edge.x*edge.y;
	
	//lines
	if(mod(gl_FragCoord.y, 3.)<1.5) color.rgb*=.7;
	else if(mod(gl_FragCoord.x, 3.)<1.) color.rgb*=.7;
	else color*=1.2;
	
	//bloom
	vec4 bloom = texture2D(bloom_texture, crtUV);
	
	gl_FragColor = vec4(color, 1.0) + bloom ;
}