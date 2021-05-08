# OpenGL-GLFW-GLAD-Template
Intended to be a scaffolding to quickly create new OpenGL projects in Visual Studio

# How to export as a multiproject Visual Studio template
Open **OpenGL-GLFW-GLAD Template Testing.vsxproj** in an XML editor and replace the parent directory in all references to `"..\OpenGL-GLFW-GLAD Template\OpenGL-GLFW-GLAD-glm-Headers.props"` and `"..\OpenGL-GLFW-GLAD Template\OpenGL-GLFW-GLAD-glm-Win32.props"` with `$ext_projectname$`.

For example:

    <Import Project="..\OpenGL-GLFW-GLAD Template\OpenGL-GLFW-GLAD-glm-Headers.props" />

Becomes

    <Import Project="..\$ext_projectname$\OpenGL-GLFW-GLAD-glm-Headers.props" />
    
Then send **MySolutionTemplate.vstemplate** and the folders **OpenGL-GLFW-GLAD Template** and **OpenGL-GLFW-GLAD Template Testing** to a zip file.

To import the template into Visual Studio simply copy it into the Visual Studio directory **Templates\ProjectTemplates**.
