from setuptools import setup, Extension

module = Extension(
    "byte",
    sources=["byte.c"])

setup(
    name="byte",
    version="1.0",
    description="a tools to change number and byte",
    ext_modules=[module]
)