#version 330

uniform sampler2D depthTexture;
const ivec2 smoothScale = ivec2(2, 2);
const float fallOff = 2.0;

out vec4 fragColor;

void main(void)
{
	ivec2 fragCoord = ivec2(gl_FragCoord.x, gl_FragCoord.y);
	float depth = texelFetch( depthTexture, fragCoord, 0 ).a;
	
	int filterRadius = 10;
	
	float sum = 0.0;
	float wsum = 0.0;
	
	for( int x= -filterRadius; x<= filterRadius; x+= 1 ) {
		float sampleDepth = texelFetch( depthTexture, fragCoord + x * smoothScale, 0 ).x;
		
		// spatial domain.
		float r = float(x) * float(smoothScale.x);
		float w = exp(-r*r);
		
		// range domain.
		//float r2 = (sampleDepth - depth) * fallOff;
		//float g = exp(-r2*r2);
		
		sum += sampleDepth * w; //* g;
		//wsum += w * g;
	}
	
	//if( wsum > 0.0 ) {
	//	sum /= wsum;
	//}
	
	fragColor.rgb = vec3(sum, sum, sum);
	fragColor.a = 0.5;
}