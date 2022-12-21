#include "menu.hpp"

void translationWindow(glm::fvec3 & translateVector) {
	ImGui::Begin("Translation window");
		ImGui::DragFloat3("Translation", (float*)&translateVector, 0.1f);
    ImGui::End();
}

void rotationWindow(glm::fvec3 & rotateAxis) {
	ImGui::Begin("Rotation window");
		ImGui::DragFloat3("Rotation", (float*)&rotateAxis, 1.f);
    ImGui::End();
}

void showMatrix(const glm::mat4 &mat, const char * matrixLabel) {
	ImGui::Begin(matrixLabel);
		ImGui::Text("%f %f %f %f", mat[0][0], mat[1][0], mat[2][0], mat[3][0]);
		ImGui::Text("%f %f %f %f", mat[0][1], mat[1][1], mat[2][1], mat[3][1]);
		ImGui::Text("%f %f %f %f", mat[0][2], mat[1][2], mat[2][2], mat[3][2]);
		ImGui::Text("%f %f %f %f", mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
	ImGui::End();
}

void vertexW_Window(float & vertex_w) {
	ImGui::Begin("Vertex W component window");
		ImGui::DragFloat("W: ", &vertex_w, 0.1f);
	ImGui::End();
}

void projectionUsage(bool &useProjectionGLM, bool &useProjectionMyOwn, bool & always_fixed_w) {
	ImGui::Begin("Using projection matrix");
		ImGui::Checkbox("GLM:", &useProjectionGLM);
		ImGui::Checkbox("My Own:", &useProjectionMyOwn);
		ImGui::Checkbox("fixed W:", &always_fixed_w);
	ImGui::End();
} 


void vertexMatrixCalculation(Vertex * vertexes, glm::mat4 &model_matrix, glm::mat4 &proj_matrix, const float & vertex_w) {
	ImGui::Begin("Vertexes multiplied");
		ImGui::Text("Model Matrix");
		ImGui::Text("%f %f %f %f", model_matrix[0][0], model_matrix[1][0], model_matrix[2][0], model_matrix[3][0]);
		ImGui::Text("%f %f %f %f", model_matrix[0][1], model_matrix[1][1], model_matrix[2][1], model_matrix[3][1]);
		ImGui::Text("%f %f %f %f", model_matrix[0][2], model_matrix[1][2], model_matrix[2][2], model_matrix[3][2]);
		ImGui::Text("%f %f %f %f", model_matrix[0][3], model_matrix[1][3], model_matrix[2][3], model_matrix[3][3]);

		ImGui::Text("\nProjection Matrix");
		ImGui::Text("%f %f %f %f", proj_matrix[0][0], proj_matrix[1][0], proj_matrix[2][0], proj_matrix[3][0]);
		ImGui::Text("%f %f %f %f", proj_matrix[0][1], proj_matrix[1][1], proj_matrix[2][1], proj_matrix[3][1]);
		ImGui::Text("%f %f %f %f", proj_matrix[0][2], proj_matrix[1][2], proj_matrix[2][2], proj_matrix[3][2]);
		ImGui::Text("%f %f %f %f", proj_matrix[0][3], proj_matrix[1][3], proj_matrix[2][3], proj_matrix[3][3]);

		glm::vec4 v[3] = {
			{vertexes[0].pos[0], vertexes[0].pos[1], vertexes[0].pos[2], vertex_w},
			{vertexes[1].pos[0], vertexes[1].pos[1], vertexes[1].pos[2], vertex_w},
			{vertexes[2].pos[0], vertexes[2].pos[1], vertexes[2].pos[2], vertex_w}
		};

		v[0] = model_matrix * v[0];
		v[1] = model_matrix * v[1];
		v[2] = model_matrix * v[2];

		ImGui::Text("\nModel * V[0]\tV[1]\tV[2]");
		ImGui::Text("%f\t%f\t%f", v[0][0], v[1][0], v[2][0]);
		ImGui::Text("%f\t%f\t%f", v[0][1], v[1][1], v[2][1]);
		ImGui::Text("%f\t%f\t%f", v[0][2], v[1][2], v[2][2]);
		ImGui::Text("%f\t%f\t%f", v[0][3], v[1][3], v[2][3]);

		v[0] = proj_matrix * v[0];
		v[1] = proj_matrix * v[1];
		v[2] = proj_matrix * v[2];

		ImGui::Text("\nProjection * V[0]\tV[1]\tV[2]");
		ImGui::Text("%f\t%f\t%f", v[0][0], v[1][0], v[2][0]);
		ImGui::Text("%f\t%f\t%f", v[0][1], v[1][1], v[2][1]);
		ImGui::Text("%f\t%f\t%f", v[0][2], v[1][2], v[2][2]);
		ImGui::Text("%f\t%f\t%f", v[0][3], v[1][3], v[2][3]);

		v[0][0] /= v[0][3];	v[1][0] /= v[1][3]; v[2][0] /= v[2][3];
		v[0][1] /= v[0][3];	v[1][1] /= v[1][3];	v[2][1] /= v[2][3];
		v[0][2] /= v[0][3];	v[1][2] /= v[1][3];	v[2][2] /= v[2][3];

		ImGui::Text("\nNDC V[0]\tV[1]\tV[2]");
		ImGui::Text("%f\t%f\t%f", v[0][0], v[1][0], v[2][0]);
		ImGui::Text("%f\t%f\t%f", v[0][1], v[1][1], v[2][1]);
		ImGui::Text("%f\t%f\t%f", v[0][2], v[1][2], v[2][2]);
		ImGui::Text("%f\t%f\t%f", v[0][3], v[1][3], v[2][3]);

	ImGui::End();
}