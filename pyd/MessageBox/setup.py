from setuptools import setup, Extension

module = Extension(
    "MessageBox",
    sources=["MessageBox.c"],
    libraries=["user32"])

setup(
    name="MessageBox",
    version="1.0",
    description="a tools connect c to python",
    ext_modules=[module]
)