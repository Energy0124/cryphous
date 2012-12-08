#version 330

in vec4 color;
out vec4 fragColor;


void main(void)
{
	vec3 normal;
	normal.xy = gl_PointCoord.xy * vec2(2.0, -2.0) + vec2(-1.0, 1.0);
	float distance = dot(normal.xy, normal.xy);
	if (distance > 1.0) {
		discard;
	}
	normal.z = sqrt( 1.0 - distance );
	vec3 lightDirection = vec3(1.0, 1.0, 1.0);
	normalize( lightDirection );

	float diffuse = max( 0.0, dot(lightDirection, normal));
	fragColor.rgb = color.rgb * diffuse;
	fragColor.a = 0.5;
}